Activate Cloud Shell
Cloud Shell is a virtual machine that is loaded with development tools. It offers a persistent 5GB home directory and runs on the Google Cloud. Cloud Shell provides command-line access to your Google Cloud resources.

Click Activate Cloud Shell Activate Cloud Shell icon at the top of the Google Cloud console.
When you are connected, you are already authenticated, and the project is set to your Project_ID, qwiklabs-gcp-04-f83520b30b4a. The output contains a line that declares the Project_ID for this session:

Your Cloud Platform project in this session is set to qwiklabs-gcp-04-f83520b30b4a
gcloud is the command-line tool for Google Cloud. It comes pre-installed on Cloud Shell and supports tab-completion.

(Optional) You can list the active account name with this command:
gcloud auth list
Copied!
Click Authorize.
Output:

ACTIVE: *
ACCOUNT: student-04-935170560b9c@qwiklabs.net

To set the active account, run:
    $ gcloud config set account `ACCOUNT`
(Optional) You can list the project ID with this command:
gcloud config list project
Copied!
Output:

[core]
project = qwiklabs-gcp-04-f83520b30b4a
Note: For full documentation of gcloud, in Google Cloud, refer to the gcloud CLI overview guide.
Ensure that the Dataflow API is successfully re-enabled
To ensure access to the necessary API, restart the connection to the Dataflow API.

In the Cloud Console, enter "Dataflow API" in the top search bar. Click on the result for Dataflow API.

Click Manage.

Click Disable API.

If asked to confirm, click Disable.

Click Enable.
When the API has been enabled again, the page will show the option to disable.

Test completed task

Click Check my progress to verify your performed task.

Assessment Completed
Disable and re-enable the Dataflow API.
Assessment Completed
Task 1. Create a Cloud BigQuery dataset and table Using Cloud Shell
Let's first create a BigQuery dataset and table.

Note: This section uses the bq command-line tool. Skip down if you want to run through this lab using the console.
Run the following command to create a dataset called taxirides:
bq mk taxirides
Copied!
Your output should look similar to:

Dataset '' successfully created
Test completed task

Click Check my progress to verify your performed task. If you have successfully created a BigQuery dataset, you will see an assessment score.

Assessment Completed!
Create a BigQuery Dataset (name: taxirides).
Assessment Completed!
Now that you have your dataset created, you'll use it in the following step to instantiate a BigQuery table.

Run the following command to do so:
bq mk \
--time_partitioning_field timestamp \
--schema ride_id:string,point_idx:integer,latitude:float,longitude:float,\
timestamp:timestamp,meter_reading:float,meter_increment:float,ride_status:string,\
passenger_count:integer -t taxirides.realtime
Copied!
Your output should look similar to:

Table 'myprojectid:taxirides.realtime' successfully created
Test completed task

Click Check my progress to verify your performed task. If you have successfully created a table in BigQuery dataset, you will see an assessment score.

Assessment Completed!
Create a table in BigQuery Dataset.
Assessment Completed!
On its face, the bq mk command looks a bit complicated. However, with some assistance from the BigQuery command-line documentation, we can break down what's going on here. For example, the documentation tells us a little bit more about schema:

Either the path to a local JSON schema file or a comma-separated list of column definitions in the form [FIELD]:[DATA_TYPE], [FIELD]:[DATA_TYPE].
In this case, we are using the latter—a comma-separated list.

Create a Cloud Storage bucket
Now that we have our table instantiated, let's create a bucket.

Use the Project ID as the bucket name to ensure a globally unique name: qwiklabs-gcp-04-f83520b30b4a

Run the following commands to do so:
export BUCKET_NAME=qwiklabs-gcp-04-f83520b30b4a
Copied!
gsutil mb gs://$BUCKET_NAME/
Copied!
Test completed task

Click Check my progress to verify your performed task. If you have successfully created a Cloud Storage bucket, you will see an assessment score.

Assessment Completed!
Create a Cloud Storage bucket.
Assessment Completed!
Once you've made your bucket, scroll down to the Run the Pipeline section.

Task 2. Create a Cloud BigQuery dataset and table using the Cloud Console
Note: Don't go through this section if you've done the command-line setup!
From the left-hand menu, in the Big Data section, click on BigQuery.

Then click Done.

Click on the three dots next to your project name under the Explorer section, then click Create dataset.

Input taxirides as your dataset ID:

Select us (multiple regions in United States) in Data location.

Leave all of the other default settings in place and click CREATE DATASET.

Test completed task

Click Check my progress to verify your performed task. If you have successfully created a BigQuery dataset, you will see an assessment score.

Assessment Completed!
Create a BigQuery Dataset (name: taxirides).
Assessment Completed!
You should now see the taxirides dataset underneath your project ID in the left-hand console.

Click on the three dots next to taxirides dataset and select Open.

Then select CREATE TABLE in the right-hand side of the console.

In the Destination > Table Name input, enter realtime.

Under Schema, toggle the Edit as text slider and enter the following:

ride_id:string,point_idx:integer,latitude:float,longitude:float,timestamp:timestamp,
meter_reading:float,meter_increment:float,ride_status:string,passenger_count:integer
Copied!
Your console should look like the following:

Create table page

Now, click Create table.
Test completed task

Click Check my progress to verify your performed task. If you have successfully created a table in BigQuery dataset, you will see an assessment score.

Assessment Completed!
Create a table in BigQuery Dataset.
Assessment Completed!
Create a Cloud Storage bucket
Go back to the Cloud Console and navigate to Cloud Storage > Buckets > Create bucket.

Use the Project ID as the bucket name to ensure a globally unique name: qwiklabs-gcp-04-f83520b30b4a

Leave all other default settings, then click Create.

Test completed task

Click Check my progress to verify your performed task. If you have successfully created a Cloud Storage bucket, you will see an assessment score.

Assessment Completed!
Create a Cloud Storage bucket.
Assessment Completed!
Task 3. Run the pipeline
Deploy the Dataflow Template:

gcloud dataflow jobs run iotflow \
    --gcs-location gs://dataflow-templates-us-west1/latest/PubSub_to_BigQuery \
    --region us-west1 \
    --worker-machine-type e2-medium \
    --staging-location gs://qwiklabs-gcp-04-f83520b30b4a/temp \
    --parameters inputTopic=projects/pubsub-public-data/topics/taxirides-realtime,outputTableSpec=qwiklabs-gcp-04-f83520b30b4a:taxirides.realtime
Copied!
In the Google Cloud Console, on the Navigation menu, click Dataflow > Jobs, and you will see your dataflow job.

Please refer the document for more information.

Note: You may need to wait a minute for the activity tracking to complete.
Test completed task

Click Check my progress to verify your performed task. If you have successfully run the Dataflow pipeline, you will see an assessment score.

Assessment Completed!
Run the Pipeline.
Assessment Completed!
You'll watch your resources build and become ready for use.

Now, let's go view the data written to BigQuery by clicking on BigQuery found in the Navigation menu.

When the BigQuery UI opens, you'll see the taxirides dataset added under your project name and realtime table underneath that.
Note: You may have to wait a few minutes for the data to populate in the BigQuery table.
Task 4. Submit a query
You can submit queries using standard SQL.

In the BigQuery Editor, add the following to query the data in your project:
SELECT * FROM `qwiklabs-gcp-04-f83520b30b4a.taxirides.realtime` LIMIT 1000
Copied!
Now click RUN.
If you run into any issues or errors, run the query again (the pipeline takes a minute to start up.)

When the query runs successfully, you'll see the output in the Query Results panel as shown below:
Query results page

Great work! You just pulled 1000 taxi rides from a Pub/Sub topic and pushed them to a BigQuery table. As you saw firsthand, templates are a practical, easy-to-use way to run Dataflow jobs. Be sure to check out, in the Dataflow Documentation, some other Google Templates in the Get started with Google-provided templates Guide.