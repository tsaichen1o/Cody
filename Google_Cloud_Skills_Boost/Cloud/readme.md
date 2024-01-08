```cpp
gcloud config set compute/region us-east1

git clone https://github.com/GoogleCloudPlatform/python-docs-samples.git
cd python-docs-samples/appengine/standard_python3/hello_world

//test
dev_appserver.py app.yaml

cd python-docs-samples/appengine/standard_python3/hello_world
nano main.py

gcloud app deploy
gcloud app browse
```

```cpp
gcloud config set compute/region us-west1
mkdir gcf_hello_world
cd gcf_hello_world
nano index.js
/**
* Background Cloud Function to be triggered by Pub/Sub.
* This function is exported by index.js, and executed when
* the trigger topic receives a message.
*
* @param {object} data The event payload.
* @param {object} context The event metadata.
*/
exports.helloWorld = (data, context) => {
const pubSubMessage = data;
const name = pubSubMessage.data
    ? Buffer.from(pubSubMessage.data, 'base64').toString() : "Hello World";

console.log(`My Cloud Function: ${name}`);
};

gsutil mb -p [PROJECT_ID] gs://[BUCKET_NAME]
gsutil mb -p 'qwiklabs-gcp-03-3ba264a669d4' gs://'qwiklabs-gcp-03-3ba264a669d4'

//When deploying a new function, you must specify 
// --trigger-topic, --trigger-bucket, or --trigger-http. 
// When deploying an update to an existing function, 
// the function keeps the existing trigger unless otherwise specified.
gcloud functions deploy helloWorld \
  --stage-bucket [BUCKET_NAME] \
  --trigger-topic hello_world \
  --runtime nodejs20

gcloud functions deploy helloWorld \
  --stage-bucket 'qwiklabs-gcp-03-3ba264a669d4' \
  --trigger-topic hello_world \
  --runtime nodejs20

gcloud functions describe helloWorld

//test
DATA=$(printf 'Hello World!'|base64) && gcloud functions call helloWorld --data '{"data":"'$DATA'"}'
//executionId: 8z7pje52qrt4

// The cloud tool returns the execution ID for the function, 
// which means a message has been written in the log.
gcloud functions logs read helloWorld
```

student_04_e7a7623e52c1@cloudshell:~/gcf_hello_world (qwiklabs-gcp-03-3ba264a669d4)$ gcloud functions describe helloWorld
automaticUpdatePolicy: {}
availableMemoryMb: 256
buildId: 6a30b057-8415-4519-a9ed-307d90956e79
buildName: projects/400417519498/locations/us-central1/builds/6a30b057-8415-4519-a9ed-307d90956e79
dockerRegistry: CONTAINER_REGISTRY
entryPoint: helloWorld
eventTrigger:
eventType: google.pubsub.topic.publish
failurePolicy: {}
resource: projects/qwiklabs-gcp-03-3ba264a669d4/topics/hello_world
service: [pubsub.googleapis.com](http://pubsub.googleapis.com/)
ingressSettings: ALLOW_ALL
labels:
deployment-tool: cli-gcloud
maxInstances: 5
name: projects/qwiklabs-gcp-03-3ba264a669d4/locations/us-central1/functions/helloWorld
runtime: nodejs20
serviceAccountEmail: [qwiklabs-gcp-03-3ba264a669d4@appspot.gserviceaccount.com](mailto:qwiklabs-gcp-03-3ba264a669d4@appspot.gserviceaccount.com)
sourceArchiveUrl: gs://qwiklabs-gcp-03-3ba264a669d4/us-central1-helloWorld-wyxpysoaipwc.zip
status: ACTIVE
timeout: 60s
updateTime: '2024-01-08T07:26:59.627Z'
versionId: '1'

student_04_e7a7623e52c1@cloudshell:~/gcf_hello_world (qwiklabs-gcp-03-3ba264a669d4)$ gcloud functions logs read helloWorld
LEVEL: D
NAME: helloWorld
EXECUTION_ID: 8z7pje52qrt4
TIME_UTC: 2024-01-08 07:28:13.012
LOG: Function execution took 71 ms, finished with status: 'ok'

LEVEL:
NAME: helloWorld
EXECUTION_ID: 8z7pje52qrt4
TIME_UTC: 2024-01-08 07:28:12.994
LOG: My Cloud Function: Hello World!

LEVEL: D
NAME: helloWorld
EXECUTION_ID: 8z7pje52qrt4
TIME_UTC: 2024-01-08 07:28:12.941
LOG: Function execution started

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/a83242af-3d6e-4898-ad33-e61f92572f0d/6141fa33-648f-4e6b-816e-7905aad3227f/Untitled.png)

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/a83242af-3d6e-4898-ad33-e61f92572f0d/ab31966c-60a6-4b9d-abce-ccf44f16552f/Untitled.png)

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/a83242af-3d6e-4898-ad33-e61f92572f0d/6fcf85a8-e853-422d-82ba-5914d5370bca/Untitled.png)

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/a83242af-3d6e-4898-ad33-e61f92572f0d/d2d9d955-8a21-4f29-93ed-47d1332e8153/Untitled.png)

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/a83242af-3d6e-4898-ad33-e61f92572f0d/8f5f7151-33bb-4957-90aa-120d4f2114e4/Untitled.png)

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/a83242af-3d6e-4898-ad33-e61f92572f0d/f0b84524-ab21-4832-b0ef-42e2d0a6b753/Untitled.png)

# Transcript

00:00Let’s move on to the next section, Containerizing and Orchestrating Apps with GKE.

00:05In this section of the course, you’ll learn about containerization and how to leverage Google Kubernetes Engine.

00:11We’ve already discussed the spectrum between infrastructure as a service and platform as a service.

00:18And we've also discussed Compute Engine, which is the IaaS offering of Google Cloud, with access to servers, file systems, and networking.

00:27Now you’ll be introduced to containers and GKE, which is a hybrid that conceptually sits between

00:31the two, offering the managed infrastructure of an IaaS, with the developer orientation of a PaaS offering.

00:38IaaS lets you share compute resources with other developers by using virtual machines to virtualize the hardware.

00:46This lets each developer deploy their own operating system, or OS, access the hardware, and

00:52build their applications in a self-contained environment with access to RAM, file systems, networking interfaces, etc.

01:00This is where containers come in.

01:02The idea of a container is to give the independent scalability of workloads in PaaS and an abstraction layer of the OS and hardware in IaaS.

01:11A configurable system lets you install your favorite runtime, web server, database, or middleware, configure the

01:18underlying system resources, such as disk space, disk I/O, or networking, and build as you like.

01:26But flexibility comes with a cost.

01:29The smallest unit of compute is an app with its VM.

01:33The guest OS might be large, even gigabytes in size, and take minutes to boot.

01:38As demand for your application increases, you have to copy an entire VM and boot the guest OS for each instance of your app, which can be slow and costly.

01:47Now, with App Engine, you have access to programming services, so you only need to write your code in self-contained workloads that use these services and include any dependent libraries.

01:59This means that as demand for your app increases, the platform scales your app seamlessly and independently by workload and infrastructure.

02:07This scales rapidly but there’s no option to fine-tune the underlying architecture to save cost.

02:13A container is an invisible box around your code and its dependencies with limited access to its own partition of the file system and hardware.

02:22It only requires a few system calls to create and it starts as quickly as a process.

02:27All that’s needed on each host is an OS kernel that supports containers and a container runtime.

02:32In essence, the OS is being virtualized.

02:35It scales like PaaS but gives you nearly the same flexibility as IaaS.

02:41This makes code ultra portable, and the OS and hardware can be treated as a black box.

02:46So you can go from development, to staging, to production, or from your laptop to the cloud, without changing or rebuilding anything.

02:55As an example, let’s say you want to scale a web server.

02:58With a container, you can do this in seconds and deploy dozens or hundreds of servers, depending on the size or your workload, on a single host.

03:08That's just a simple example of scaling one container running the whole application on a single host.

03:13However, you'll probably want to build your applications using lots of containers, each performing their own function, as is done when using a microservices architecture.

03:23If you build applications this way and connect them with network connections, you can make them modular, easily deployable, and scaled independently across a group of hosts.

03:34The hosts can scale up and down and start and stop containers as demand for your app changes or as hosts fail.

03:42Kubernetes is a container orchestration tool you can use to simplify the management of containerized environments.

03:49You can install Kubernetes on a group of your own managed servers or run it as a hosted service

03:54in Google Cloud on a cluster of managed Compute Engine instances called Google Kubernetes Engine (more on that shortly).

04:02Kubernetes was built by Google to run applications at scale.

04:06It lets you install the system on local servers in the cloud, manage container networking and data storage, deploy rollouts and rollbacks, and monitor and manage container and host health.

04:18A software container makes it easier for teams to package, manage, and ship their code.

04:23They write software applications that run in a container.

04:26The container provides the operating system needed to run their application.

04:31The container will run on any container platform.

04:34This can save a lot of time and cost compared to running servers or virtual machines.

04:38Like a virtual machine imitates a computer, a container imitates an operating system.

04:45Everything at Google runs on containers: Gmail, Web search, Maps, MapReduce, batch, Google File System, Colossus, even Cloud Functions (VMs in containers).

04:57Google launches over 2 billion containers per week.

05:01Docker is the tool that puts the application and everything it needs in the container.

05:06Once the application is in a container, it can be moved anywhere that will run Docker containers—any laptop, server, or cloud provider.

05:15This portability makes code easier to produce, manage, troubleshoot, and update.

05:21For service providers, containers make it easy to develop code that can be easily transferred and run both in the cloud and on a customer's on-premises servers.

05:30Kubernetes is an open source container orchestration tool for managing a cluster of Docker Linux containers as a single system.

05:38It can be run in the cloud and on-premises environments.

05:41It’s inspired and informed by Google’s experiences and internal systems.

05:48Google Kubernetes Engine, GKE, is a managed environment for deploying containerized apps.

05:54It brings Google’s latest innovations in developer productivity, resource efficiency, automated operations, and open source flexibility to accelerate time to market.

06:04GKE is a powerful cluster manager and orchestration system for running Docker containers in Google Cloud.

06:11GKE manages containers automatically based on specifications such as CPU and memory.

06:18It's built on the open source Kubernetes system, making it easy for users to orchestrate container clusters or groups

06:22of containers, and it also gives customers the flexibility to take advantage of on-premises, hybrid, or public cloud infrastructure.

# Kubernetes on Google Cloud

When you run a GKE cluster, you also gain the benefit of advanced cluster management features that Google Cloud provides. These include:

- [Load balancing](https://cloud.google.com/compute/docs/load-balancing-and-autoscaling) for Compute Engine instances
- [Node pools](https://cloud.google.com/kubernetes-engine/docs/node-pools) to designate subsets of nodes within a cluster for additional flexibility
- [Automatic scaling](https://cloud.google.com/kubernetes-engine/docs/cluster-autoscaler) of your cluster's node instance count
- [Automatic upgrades](https://cloud.google.com/kubernetes-engine/docs/node-auto-upgrade) for your cluster's node software
- [Node auto-repair](https://cloud.google.com/kubernetes-engine/docs/how-to/node-auto-repair) to maintain node health and availability
- [Logging and Monitoring](https://cloud.google.com/kubernetes-engine/docs/how-to/logging) with Cloud Monitoring for visibility into your cluster

```cpp
gcloud config set compute/region us-west1
gcloud config set compute/zone us-west1-c

gcloud container clusters create --machine-type=e2-medium --zone=us-east4-c lab-cluster
gcloud container clusters get-credentials lab-cluster

// To create a new Deployment hello-server from the hello-app container image, run the following kubectl create command:
kubectl create deployment hello-server --image=gcr.io/google-samples/hello-app:1.0

// To create a Kubernetes Service, which is a Kubernetes resource that lets you expose your application to external traffic, run the following kubectl expose command:
kubectl expose deployment hello-server --type=LoadBalancer --port 8080

kubectl get service

http://[EXTERNAL-IP]:8080

// delete the cluster
gcloud container clusters delete lab-cluster
```