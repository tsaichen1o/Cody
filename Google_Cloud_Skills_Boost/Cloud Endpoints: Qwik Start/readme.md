Task 1. Getting the sample code
Enter the following command in Cloud Shell to get the sample API and scripts:
gsutil cp gs://spls/gsp164/endpoints-quickstart.zip .
unzip endpoints-quickstart.zip
Copied!
Change to the directory that contains the sample code:
cd endpoints-quickstart
Copied!
Task 2. Deploying the Endpoints configuration
To publish a REST API to Endpoints, an OpenAPI configuration file that describes the API is required. The lab's sample API comes with a pre-configured OpenAPI file called openapi.yaml.

Endpoints uses Google Service Management, an infrastructure service of Google Cloud, to create and manage APIs and services. To use Endpoints to manage an API, you deploy the API's OpenAPI configuration to Service Management.

To deploy the Endpoints configuration...

In the endpoints-qwikstart directory, enter the following:
cd scripts
Copied!
Run the following script, which is included in the sample:
./deploy_api.sh
Copied!
Cloud Endpoints uses the host field in the OpenAPI configuration file to identify the service. The deploy_api.sh script sets the ID of your Cloud project as part of the name configured in the host field. (When you prepare an OpenAPI configuration file for your own service, you will need to do this manually.)

The script then deploys the OpenAPI configuration to Service Management using the command: gcloud endpoints services deploy openapi.yaml

As it is creating and configuring the service, Service Management outputs some information to the console. You can safely ignore the warnings about the paths in openapi.yaml not requiring an API key. On successful completion, you see a line like the following that displays the service configuration ID and the service name:

Service Configuration [2017-02-13-r2] uploaded for service [airports-api.endpoints.example-project.cloud.goog]
Click Check my progress to verify the objective.
Assessment Completed!
Deploying the Endpoints configuration.
Assessment Completed!

Task 3. Deploying the API backend
So far you have deployed the OpenAPI configuration to Service Management, but you have not yet deployed the code that will serve the API backend. The deploy_app.sh script included in the lab sample creates an App Engine flexible environment to host the API backend, and then the script deploys the API to App Engine.

To deploy the API backend, make sure you are in the endpoints-quickstart/scripts directory. Then, run the following script:
./deploy_app.sh
Copied!
The script runs the following command to create an App Engine flexible environment in the us-west1 region: gcloud app create --region="$REGION"

It takes a couple minutes to create the App Engine flexible backend.

Note: If you get an ERROR: NOT_FOUND: Unable to retrieve P4SA: from GAIA message, rerun the deploy_app.sh script.
You'll see the following displayed in Cloud Shell after the App Engine is created:

Success! The app is now created. Please use `gcloud app deploy` to deploy your first app.
The script goes on to run the gcloud app deploy command to deploy the sample API to App Engine.

You'll then see a line like the following in Cloud Shell:

Deploying ../app/app_template.yaml...You are about to deploy the following services:
It takes several minutes for the API to be deployed to App Engine. You'll see a line like the following when the API is successfully deployed to App Engine:

Deployed service [default] to [https://example-project.appspot.com]
Click Check my progress to verify the objective.
Assessment Completed!
Deploying the API backend.
Assessment Completed!

Task 4. Sending requests to the API
After deploying the sample API, you can send requests to it by running the following script:
./query_api.sh
Copied!
The script echoes the curl command that it uses to send a request to the API, and then displays the result. You'll see something like the following in Cloud Shell:

curl "https://example-project.appspot.com/airportName?iataCode=SFO"
San Francisco International Airport
The API expects one query parameter, iataCode, that is set to a valid IATA airport code such as SEA or JFK.

To test, run this example in Cloud Shell:
./query_api.sh JFK
Copied!
You just deployed and tested an API in Cloud Endpoints!

Click Check my progress to verify the objective.
Assessment Completed!
Sending requests to the API.
Assessment Completed!

Task 5. Tracking API activity
With APIs deployed with Cloud Endpoints, you can monitor critical operations metrics in the Cloud Console and gain insight into your users and usage with Cloud Logging:

Run this traffic generation script in Cloud Shell to populate the graphs and logs:
./generate_traffic.sh
Copied!
Note: This script generates requests in a loop and automatically times out in 5 minutes. To end the script sooner, enter CTRL+C in Cloud Shell.
In the Console, go to Navigation menu > Endpoints > Services and click Airport Codes service to look at the activity graphs for your service. It may take a few moments for the requests to be reflected in the graphs. You can do this while you wait for data to be displayed:
If the Permissions side panel is not open, click Show Permissions Panel. The Permissions panel allows you to control who has access to your API and the level of access.

Click the Deployment history tab. This tab displays a history of your API deployments, including the deployment time and who deployed the change.

Click the Overview tab. Here you'll see the traffic coming in. After the traffic generation script has been running for a minute, scroll down to see the three lines on the Total latency graph (50th, 95th, and 99th percentiles). This data provides a quick estimate of response times.

At the bottom of the Endpoints graphs, under Method, click the View logs link for GET/airportName. The Logs Viewer page displays the request logs for the API.

Enter CTRL+C in Cloud Shell to stop the script.

Task 6. Add a quota to the API
Note: This is a beta release of Quotas. This feature might be changed in backward-incompatible ways and is not subject to any SLA or deprecation policy.
Cloud Endpoints lets you set quotas so you can control the rate at which applications can call your API. Quotas can be used to protect your API from excessive usage by a single client.

Deploy the Endpoints configuration that has a quota:

./deploy_api.sh ../openapi_with_ratelimit.yaml
Copied!
Redeploy your app to use the new Endpoints configuration (this may take a few minutes):

./deploy_app.sh
Copied!
Click Check my progress to verify the objective.
Assessment Completed!
Add a quota to the API.
Assessment Completed!

In the Console, navigate to Navigation menu > APIs & Services > Credentials.

Click Create credentials and choose API key. A new API key is displayed on the screen.

Click the Copy to clipboard icon to copy it to your clipboard.

In Cloud Shell, type the following. Replace YOUR-API-KEY with the API key you just created:

export API_KEY=YOUR-API-KEY
Copied!
Send your API a request using the API key variable you just created:

./query_api_with_key.sh $API_KEY
Copied!
You'll see something like the following on the console:

curl -H 'x-api-key: AIzeSyDbdQdaSdhPMdiAuddd_FALbY7JevoMzAB' "https://example-project.appspot.com/airportName?iataCode=SFO"
San Francisco International Airport
The API now has a limit of 5 requests per second. Run the following command to send traffic to the API and trigger the quota limit:

./generate_traffic_with_key.sh $API_KEY
Copied!
After running the script for 5-10 seconds, enter CTRL+C in Cloud Shell to stop the script.

Send another authenticated request to the API:

./query_api_with_key.sh $API_KEY
Copied!
You'll see something like the following on the console:

{
     "code": 8,
     "message": "Insufficient tokens for quota 'airport_requests' and limit 'limit-on-airport-requests' of service 'example-project.appspot.com' for consumer 'api_key:AIzeSyDbdQdaSdhPMdiAuddd_FALbY7JevoMzAB'.",
     "details": [
      {
       "@type": "type.googleapis.com/google.rpc.DebugInfo",
       "stackEntries": [],
       "detail": "internal"
      }
     ]
    }
If you get a different response, try running the generate_traffic_with_key.sh script again and retry.
