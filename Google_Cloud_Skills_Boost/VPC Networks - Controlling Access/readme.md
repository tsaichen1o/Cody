Task 1. Create the web servers
In this section, you will create two web servers (blue and green) in the default VPC network. Then, you will install nginx on the web servers and modify the welcome page to distinguish the servers.

Create the blue server
Create the blue server with a network tag.

In the Console, navigate to Navigation menu (Navigation menu icon) > Compute Engine > VM instances.

Click Create Instance.

Set the following values, leave all other values at their defaults:

Property	Value (type value or select option as specified)
Name	blue
Region	us-east4
Zone	us-east4-a
For more information on available regions and zones, in the Google Cloud Compute Engine Region and Zone guide, see the Available regions and zones section of the Compute Engine Guides.

Click Advanced Options > Networking.

For Network tags, type web-server.

Note: Networks use network tags to identify which VM instances are subject to certain firewall rules and network routes. Later in this lab, you create a firewall rule to allow HTTP access for VM instances with the web-server tag. Alternatively, you could check the Allow HTTP traffic checkbox, which would tag this instance as http-server and create the tagged firewall rule for tcp:80 for you.
Click Create.
Test Completed Task
Click Check my progress to verify your performed task. If you have completed the task successfully you will be granted an assessment score.

Assessment Completed!
Create the blue server.
Assessment Completed!
Create the green server
Create the green server without a network tag.

Still in the Console, on the VM instances page, click Create Instance.

Set the following values, leave all other values at their defaults:

Property	Value (type value or select option as specified)
Name	green
Region	us-east4
Zone	us-east4-a
Click Create.

Test Completed Task
Click Check my progress to verify your performed task. If you have completed the task successfully you will be granted an assessment score.

Assessment Completed!
Create the green server.
Assessment Completed!
Install nginx and customize the welcome page
Install nginx on both VM instances and modify the welcome page to distinguish the servers.

Still in the VM instances dialog, for blue, click SSH to launch a terminal and connect.

In the SSH terminal to blue, run the following command to install nginx:

sudo apt-get install nginx-light -y
Copied!
Open the welcome page in the nano editor:
sudo nano /var/www/html/index.nginx-debian.html
Copied!
Replace the <h1>Welcome to nginx!</h1> line with <h1>Welcome to the blue server!</h1>.
Press CTRL+o, ENTER, CTRL+x.
Verify the change:
cat /var/www/html/index.nginx-debian.html
Copied!
The output should contain the following:

<h1>Welcome to the blue server!</h1>
<p>If you see this page, the nginx web server is successfully installed and
working. Further configuration is required.</p>
Close the SSH terminal to blue:
exit
Copied!
Repeat the same steps for the green server:

For green, click SSH to launch a terminal and connect.
Install nginx:
sudo apt-get install nginx-light -y
Copied!
Open the welcome page in the nano editor:
sudo nano /var/www/html/index.nginx-debian.html
Copied!
Replace the <h1>Welcome to nginx!</h1> line with <h1>Welcome to the green server!</h1>.
Press CTRL+o, ENTER, CTRL+x.
Verify the change:
cat /var/www/html/index.nginx-debian.html
Copied!
The output should contain the following:

<h1>Welcome to the green server!</h1>
<p>If you see this page, the nginx web server is successfully installed and
working. Further configuration is required.</p>
Close the SSH terminal to green:
exit
Copied!
Test Completed Task
Click Check my progress to verify your performed task. If you have completed the task successfully you will be granted an assessment score.

Assessment Completed!
Install Nginx and customize the welcome page.
Assessment Completed!
Task 2. Create the firewall rule
Create the tagged firewall rule and test HTTP connectivity.

Create the tagged firewall rule
Create a firewall rule that applies to VM instances with the web-server network tag.

In the Console, navigate to Navigation menu (Navigation menu icon) > VPC network > Firewall.
Notice the default-allow-internal firewall rule.
Note: The default-allow-internal firewall rule allows traffic on all protocols/ports within the default network. You want to create a firewall rule to allow traffic from outside this network to only the blue server, by using the network tag web-server.
Click Create Firewall Rule.

Set the following values, leave all other values at their defaults.

Property	Value (type value or select option as specified)
Name	allow-http-web-server
Network	default
Targets	Specified target tags
Target tags	web-server
Source filter	IPv4 Ranges
Source IPv4 ranges	0.0.0.0/0
Protocols and ports	Specified protocols and ports, and then check tcp, type: 80; and check Other protocols, type: icmp.
Note: Make sure to include the /0 in the Source IP ranges to specify all networks.
Click Create.
Test Completed Task
Click Check my progress to verify your performed task. If you have completed the task successfully you will be granted an assessment score.

Assessment Completed!
Create the tagged firewall rule.
Assessment Completed!
Create a test-vm
Create a test-vm instance using the Cloud Shell command line.

Open a new Cloud Shell terminal.

Run the following command to create a test-vm instance, in the us-east4-a zone:

gcloud compute instances create test-vm --machine-type=e2-micro --subnet=default --zone=us-east4-a
Copied!
The output should look like this:

NAME     ZONE           MACHINE_TYPE  PREEMPTIBLE  INTERNAL_IP  EXTERNAL_IP    STATUS
test-vm  us-east4-a  e2-micro                   10.142.0.4   35.237.134.68  RUNNING
Note: You can easily create VM instances from the Console or the gcloud command line.
Test Completed Task
Click Check my progress to verify your performed task. If you have completed the task successfully you will be granted an assessment score.

Assessment Completed!
Create a test-vm.
Assessment Completed!
Test HTTP connectivity
From the test-vm, curl the internal and external IP addresses of blue and green.

In the Console, navigate to Navigation menu (Navigation menu icon) > Compute Engine > VM instances.
Note the internal and external IP addresses of blue and green.
For test-vm, click SSH to launch a terminal and connect.
To test HTTP connectivity to blue's internal IP, run the following command, replacing blue's internal IP:
curl <Enter blue's internal IP here>
Copied!
You should see the Welcome to the blue server! header.

To test HTTP connectivity to green's internal IP, run the following command, replacing green's internal IP:
curl -c 3 <Enter green's internal IP here>
Copied!
You should see the Welcome to the green server! header.

Note: You are able to HTTP access both servers using their internal IP addresses. The connection on tcp:80 is allowed by the default-allow-internal firewall rule, as test-vm is on the same VPC network as the web server's default network.
To test HTTP connectivity to blue's external IP, run the following command, replacing blue's external IP:
curl <Enter blue's external IP here>
Copied!
You should see the Welcome to the blue server! header.

To test HTTP connectivity to green's external IP, run the following command, replacing green's external IP:
curl -c 3 <Enter green's external IP here>
Copied!
Note: This should not work! The request hangs.
Press CTRL+c to stop the HTTP request.
Note: As expected, you are only able to HTTP access the external IP address of the blue server as the allow-http-web-server only applies to VM instances with the web-server tag.
You can verify the same behavior from your browser by opening a new tab and navigating to http://[External IP of server].

Task 3. Explore the Network and Security Admin roles
Cloud IAM lets you authorize who can take action on specific resources, giving you full control and visibility to manage cloud resources centrally. The following roles are used in conjunction with single-project networking to independently control administrative access to each VPC Network:

Network Admin: Permissions to create, modify, and delete networking resources, except for firewall rules and SSL certificates.
Security Admin: Permissions to create, modify, and delete firewall rules and SSL certificates.
Explore these roles by applying them to a service account, which is a special Google account that belongs to your VM instance, instead of to an individual end user. Rather than creating a new user, you will authorize test-vm to use the service account to demonstrate the permissions of the Network Admin and Security Admin roles.

Verify current permissions
Currently, test-vm uses the Compute Engine default service account, which is enabled on all instances created by Cloud Shell command-line and the Cloud Console.

Try to list or delete the available firewall rules from test-vm.

Return to the SSH terminal of the test-vm instance.
Try to list the available firewall rules:
gcloud compute firewall-rules list
Copied!
The output should look like this:

ERROR: (gcloud.compute.firewall-rules.list) Some requests did not succeed:
 - Insufficient Permission
Note: This should not work!
Try to delete the allow-http-web-server firewall rule:
gcloud compute firewall-rules delete allow-http-web-server
Copied!
Enter Y, if asked to continue.
The output should look like this:

ERROR: (gcloud.compute.firewall-rules.delete) Could not fetch resource:
 - Insufficient Permission
Note: This should not work!
Note: The Compute Engine default service account does not have the right permissions to allow you to list or delete firewall rules. The same applies to other users who do not have the right roles.
Create a service account
Create a service account and apply the Network Admin role.

In the Console, navigate to Navigation menu (Navigation menu icon) > IAM & admin > Service Accounts.

Notice the Compute Engine default service account.

Click Create service account.

Set the Service account name to Network-admin and click CREATE AND CONTINUE.

For Select a role, select Compute Engine > Compute Network Admin and click CONTINUE then click DONE.

After creating the service account Network-admin, click on the three dots at the right corner and click Manage Keys in the dropdown, then click on Add Key and select Create new key from the dropdown. Click Create to download your JSON output.

Click Close.

A JSON key file download to your local computer. Find this key file, you will upload it into the VM in a later step.

Rename the JSON key file on your local machine to credentials.json

Test Completed Task
Click Check my progress to verify your performed task. If you have completed the task successfully you will be granted an assessment score.

Assessment Completed!
Create a Network-admin service account.
Assessment Completed!
Authorize test-vm and verify permissions
Authorize test-vm to use the Network-admin service account.

One or more of your choices is incorrect.

The Network Admin role provides permissions to:

Modify the available firewall rules

Create a firewall rules

List the available firewall rules

Neither list, create, modify, or delete the available firewall rules

Delete the available firewall rules
One or more of your choices is incorrect.

Return to the SSH terminal of the test-vm instance.
To upload credentials.json through the SSH VM terminal, click on the Upload file icon in the upper-right corner.
Select credentials.json and upload it.
Click Close in the File Transfer window.
Note: If prompted, click Retry on the Connection via Cloud Identity-Aware Proxy Failed dialog and re-upload the file.
Authorize the VM with the credentials you just uploaded:
gcloud auth activate-service-account --key-file credentials.json
Copied!
Note: The image you are using has the Cloud SDK pre-installed; therefore, you don’t need to initialize the Cloud SDK. If you are attempting this lab in a different environment, make sure you have followed the procedures regarding installing the Cloud SDK.
Try to list the available firewall rules:
gcloud compute firewall-rules list
Copied!
The output should look like this:

NAME                    NETWORK  DIRECTION  PRIORITY  ALLOW     DENY
allow-http-web-server   default  INGRESS    1000      tcp:80
default-allow-icmp      default  INGRESS    65534     icmp
default-allow-internal  default  INGRESS    65534     all
default-allow-rdp       default  INGRESS    65534     tcp:3389
default-allow-ssh       default  INGRESS    65534     tcp:22
This should work!

Try to delete the allow-http-web-server firewall rule:
gcloud compute firewall-rules delete allow-http-web-server
Copied!
Enter Y, if asked to continue.
The output should look like this:

ERROR: (gcloud.compute.firewall-rules.delete) Could not fetch resource:
 - Required 'compute.firewalls.delete' permission for 'projects/[PROJECT_ID]/global/firewalls/allow-http-web-server'
Note: This should not work!
Note: As expected, the Network Admin role has permissions to list but not modify/delete firewall rules.
Update service account and verify permissions
Update the Network-admin service account by providing it the Security Admin role.


The Security Admin role, provides permissions to:

Neither list, create, modify, or delete the available firewall rules

Create a firewall rules

Delete the available firewall rules

Modify the available firewall rules

List the available firewall rules

In the Console, navigate to Navigation menu (Navigation menu icon) > IAM & admin > IAM.

Find the Network-admin account. Focus on the Name column to identify this account.

Click on the pencil icon for the Network-admin account.

Change Role to Compute Engine > Compute Security Admin.

Click Save.

Return to the SSH terminal of the test-vm instance.

Try to list the available firewall rules:

gcloud compute firewall-rules list
Copied!
The output should look like this:

NAME                    NETWORK  DIRECTION  PRIORITY  ALLOW     DENY
allow-http-web-server   default  INGRESS    1000      tcp:80
default-allow-icmp      default  INGRESS    65534     icmp
default-allow-internal  default  INGRESS    65534     all
default-allow-rdp       default  INGRESS    65534     tcp:3389
default-allow-ssh       default  INGRESS    65534     tcp:22
This should work!

Try to delete the allow-http-web-server firewall rule:
gcloud compute firewall-rules delete allow-http-web-server
Copied!
Enter Y, if asked to continue.
The output should look like this:

Deleted [https://www.googleapis.com/compute/v1/projects/qwiklabs-gcp-00e186e4b1cec086/global/firewalls/allow-http-web-server].
This should work!

Note: As expected, the Security Admin role has permissions to list and delete firewall rules.
Verify the deletion of the firewall rule
Verify that you can no longer HTTP access the external IP of the blue server, because you deleted the allow-http-web-server firewall rule.

Return to the SSH terminal of the test-vm instance.
To test HTTP connectivity to blue's external IP, run the following command, replacing blue's external IP:
curl -c 3 <Enter blue's external IP here>
Copied!
Note: This should not work!
Press CTRL+c to stop the HTTP request.
Note: Provide the Security Admin role to the right user or service account to avoid any unwanted changes to your firewall rules!
