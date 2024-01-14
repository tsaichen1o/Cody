Set your region and zone
Certain Compute Engine resources live in regions and zones. A region is a specific geographical location where you can run your resources. Each region has one or more zones.

Learn more about regions and zones and see a complete list in Regions & Zones documentation.
Run the following gcloud commands in Cloud Console to set the default region and zone for your lab:

gcloud config set compute/zone "us-east4-a"
export ZONE=$(gcloud config get compute/zone)

gcloud config set compute/region "us-east4"
export REGION=$(gcloud config get compute/region)
Copied!
Task 1. Create a Compute Engine instance
In the Cloud Console dashboard, go to Navigation menu > Compute Engine > VM instances, then click Create instance.

Fill in the fields as follows, leaving all other fields at the default value:

Field	Value
Name	lamp-1-vm
Region	us-east4
Zone	us-east4-a
Series	E2
Machine type	e2-medium
Boot disk	Debian GNU/Linux 11 (bullseye)
Firewall	Check Allow HTTP traffic
Click Create.

Wait a couple of minutes, you'll see a green check when the instance has launched.

Click Check my progress below. A green check confirms you're on track.

Assessment Completed!
Create a Compute Engine instance
Assessment Completed!
Task 2. Add Apache2 HTTP Server to your instance
In the Console, click SSH in line with lamp-1-vm to open a terminal to your instance.

Run the following commands in the SSH window to set up Apache2 HTTP Server:

sudo apt-get update
Copied!
sudo apt-get install apache2 php7.0
Copied!
When asked if you want to continue, enter Y.
Note: If you cannot install php7.0, use php5.
sudo service apache2 restart
Copied!
Click Check my progress below. A green check confirms you're on track.

Assessment Completed!
Add Apache2 HTTP Server to your instance
Assessment Completed!
Return to the Cloud Console, on the VM instances page. Click the External IP for lamp-1-vm instance to see the Apache2 default page for this instance.
Note: If you are unable to find External IP column then click on Column Display Options icon on the right side of the corner, select External IP checkbox and click OK.
Click Check my progress below. A green check confirms you're on track.

Assessment Completed!
Get a success response over External IP of VM instance
Assessment Completed!
Create a Monitoring Metrics Scope
Set up a Monitoring Metrics Scope that's tied to your Google Cloud Project. The following steps create a new account that has a free trial of Monitoring.

In the Cloud Console, click Navigation menu (Navigation menu icon) > Monitoring.
When the Monitoring Overview page opens, your metrics scope project is ready.

Install the Monitoring and Logging agents
Agents collect data and then send or stream info to Cloud Monitoring in the Cloud Console.

The Cloud Monitoring agent is a collected-based daemon that gathers system and application metrics from virtual machine instances and sends them to Monitoring. By default, the Monitoring agent collects disk, CPU, network, and process metrics. Configuring the Monitoring agent allows third-party applications to get the full list of agent metrics. On the Google Cloud, Operations website, see Cloud Monitoring Documentation for more information.

In this section, you install the Cloud Logging agent to stream logs from your VM instances to Cloud Logging. Later in this lab, you see what logs are generated when you stop and start your VM.

Note: It is best practice to run the Cloud Logging agent on all your VM instances.
Run the Monitoring agent install script command in the SSH terminal of your VM instance to install the Cloud Monitoring agent:
curl -sSO https://dl.google.com/cloudagents/add-google-cloud-ops-agent-repo.sh
Copied!
sudo bash add-google-cloud-ops-agent-repo.sh --also-install
Copied!
If asked if you want to continue, press Y.

Run the Logging agent install script command in the SSH terminal of your VM instance to install the Cloud Logging agent:

sudo systemctl status google-cloud-ops-agent"*"
Copied!
Press q to exit the status.

sudo apt-get update
Copied!
Task 3. Create an uptime check
Uptime checks verify that a resource is always accessible. For practice, create an uptime check to verify your VM is up.

In the Cloud Console, in the left menu, click Uptime checks, and then click Create Uptime Check.

For Protocol, select HTTP.

For Resource Type, select Instance.

For Instance, select lamp-1-vm.

For Check Frequency, select 1 minute.

Click Continue.

In Response Validation, accept the defaults and then click Continue.

In Alert & Notification, accept the defaults, and then click Continue.

For Title, type Lamp Uptime Check.

Click Test to verify that your uptime check can connect to the resource.

When you see a green check mark everything can connect.

Click Create.

The uptime check you configured takes a while for it to become active. Continue with the lab, you'll check for results later. While you wait, create an alerting policy for a different resource.

Task 4. Create an alerting policy
Use Cloud Monitoring to create one or more alerting policies.

In the left menu, click Alerting, and then click +Create Policy.

Click on Select a metric dropdown. Uncheck the Active.

Type Network traffic in filter by resource and metric name and click on VM instance > Interface. Select Network traffic (agent.googleapis.com/interface/traffic) and click Apply. Leave all other fields at the default value.

Click Next.

Set the Threshold position to Above threshold, Threshold value to 500 and Advanced Options > Retest window to 1 min. Click Next.

Click on the drop down arrow next to Notification Channels, then click on Manage Notification Channels.

A Notification channels page will open in a new tab.

Scroll down the page and click on ADD NEW for Email.

In the Create Email Channel dialog box, enter your personal email address in the Email Address field and a Display name.

Click on Save.

Go back to the previous Create alerting policy tab.

Click on Notification Channels again, then click on the Refresh icon to get the display name you mentioned in the previous step.

Click on Notification Channels again if necessary, select your Display name and click OK.

Add a message in documentation, which will be included in the emailed alert.

Mention the Alert name as Inbound Traffic Alert.

Click Next.

Review the alert and click Create Policy.

You've created an alert! While you wait for the system to trigger an alert, create a dashboard and chart, and then check out Cloud Logging.

Click Check my progress below. A green check confirms you're on track.

Assessment Completed!
Create an uptime check and alerting policy
Assessment Completed!
Task 5. Create a dashboard and chart
You can display the metrics collected by Cloud Monitoring in your own charts and dashboards. In this section you create the charts for the lab metrics and a custom dashboard.

In the left menu select Dashboards, and then +Create Dashboard.

Name the dashboard Cloud Monitoring LAMP Qwik Start Dashboard.

Add the first chart
Click on + ADD WIDGET

Select the Line option under Visualization in the Add widget.

Name the Widget title CPU Load.

Click on Resource & Metric dropdown. Uncheck the Active.

Type CPU load (1m) in filter by resource and metric name and click on VM instance > Cpu. Select CPU load (1m) and click Apply. Leave all other fields at the default value. Refresh the tab to view the graph.

Add the second chart
Click + Add WIDGET and select Line option under Visualization in the Add widget.

Name this Widget title Received Packets.

Click on Resource & Metric dropdown. Uncheck the Active resources & metrics.

Type Received packets in filter by resource and metric name and click on VM instance > Instance. Select Received packets and click Apply. Refresh the tab to view the graph.

Leave the other fields at their default values. You see the chart data.

Task 6. View your logs
Cloud Monitoring and Cloud Logging are closely integrated. Check out the logs for your lab.

Select Navigation menu > Logging > Logs Explorer.

Select the logs you want to see, in this case, you select the logs for the lamp-1-vm instance you created at the start of this lab:

Click on Resource.

Select VM Instance > lamp-1-vm in the Resource drop-down menu.

Click Apply.

Leave the other fields with their default values.

Click the Stream logs.

You see the logs for your VM instance.

Check out what happens when you start and stop the VM instance.
To best see how Cloud Monitoring and Cloud Logging reflect VM instance changes, make changes to your instance in one browser window and then see what happens in the Cloud Monitoring, and then Cloud Logging windows.

Open the Compute Engine window in a new browser window. Select Navigation menu > Compute Engine, right-click VM instances > Open link in new window.

Move the Logs Viewer browser window next to the Compute Engine window. This makes it easier to view how changes to the VM are reflected in the logs

In the Compute Engine window, select the lamp-1-vm instance, click the three vertical dots at the right of the screen and then click Stop, and then confirm to stop the instance.

It takes a few minutes for the instance to stop.

Watch in the Logs View tab for when the VM is stopped.

In the VM instance details window, click the three vertical dots at the right of the screen and then click Start/resume, and then confirm. It will take a few minutes for the instance to re-start. Watch the log messages to monitor the start up.

Task 7. Check the uptime check results and triggered alerts
In the Cloud Logging window, select Navigation menu > Monitoring > Uptime checks. This view provides a list of all active uptime checks, and the status of each in different locations.

You will see Lamp Uptime Check listed. Since you have just restarted your instance, the regions are in a failed status. It may take up to 5 minutes for the regions to become active. Reload your browser window as necessary until the regions are active.

Click the name of the uptime check, Lamp Uptime Check.

Since you have just restarted your instance, it may take some minutes for the regions to become active. Reload your browser window as necessary.

Check if alerts have been triggered
In the left menu, click Alerting.

You see incidents and events listed in the Alerting window.

Check your email account. You should see Cloud Monitoring Alerts.

Note: Remove the email notification from your alerting policy. The resources for the lab may be active for a while after you finish, and this may result in a few more email notifications getting sent out.
Congratulations!
You have successfully set up and monitored a VM with Cloud Monitoring.

Finish your Quest
This self-paced lab is part of the Google Cloud's Operations Suite, Baseline: Infrastructure, Cloud Engineering, and Optimizing Your Google Cloud Costs quests. A quest is a series of related labs that form a learning path. Enroll in any quest that contains this lab and get immediate completion credit. See the Google Cloud Skills Boost catalog to see all available quests.