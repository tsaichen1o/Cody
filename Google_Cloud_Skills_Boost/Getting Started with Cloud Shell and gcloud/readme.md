Welcome to Cloud Shell! Type "help" to get started.
Your Cloud Platform project in this session is set to qwiklabs-gcp-01-ffab54b71b55.
Use “gcloud config set project [PROJECT_ID]” to change to a different project.
student_00_c13ac57de5dd@cloudshell:~ (qwiklabs-gcp-01-ffab54b71b55)$ gcloud auth list
Credentialed Accounts

ACTIVE: *
ACCOUNT: student-00-c13ac57de5dd@qwiklabs.net

To set the active account, run:
    $ gcloud config set account `ACCOUNT`

student_00_c13ac57de5dd@cloudshell:~ (qwiklabs-gcp-01-ffab54b71b55)$ gcloud config list project
[core]
project = qwiklabs-gcp-01-ffab54b71b55

Your active configuration is: [cloudshell-19351]
student_00_c13ac57de5dd@cloudshell:~ (qwiklabs-gcp-01-ffab54b71b55)$ gcloud config set compute/region us-central1
Updated property [compute/region].
student_00_c13ac57de5dd@cloudshell:~ (qwiklabs-gcp-01-ffab54b71b55)$ gcloud config get-value compute/region
Your active configuration is: [cloudshell-19351]
us-central1
student_00_c13ac57de5dd@cloudshell:~ (qwiklabs-gcp-01-ffab54b71b55)$ gcloud config set compute/zone us-central1-c
Updated property [compute/zone].
student_00_c13ac57de5dd@cloudshell:~ (qwiklabs-gcp-01-ffab54b71b55)$ gcloud config get-value compute/zone
Your active configuration is: [cloudshell-19351]
us-central1-c
student_00_c13ac57de5dd@cloudshell:~ (qwiklabs-gcp-01-ffab54b71b55)$ gcloud config get-value project
Your active configuration is: [cloudshell-19351]
qwiklabs-gcp-01-ffab54b71b55
student_00_c13ac57de5dd@cloudshell:~ (qwiklabs-gcp-01-ffab54b71b55)$ gcloud compute project-info describe --project $(gcloud config get-value project)
Your active configuration is: [cloudshell-19351]
commonInstanceMetadata:
  fingerprint: qIR7ytmlUtE=
  items:
  - key: google-compute-default-zone
    value: us-central1-c
  - key: google-compute-default-region
    value: us-central1
  - key: ssh-keys
    value: student-00-c13ac57de5dd:ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQCqPyTnnpG3QSBxYjFrOD2Nmgjby2FeyIp9Veofq47js0sfpxypf2Da69b2oEVtEWbYCz2/f2CIwsI/0lxf9atKugUqJk+/ae7Y8GweG7L0PzbLtUlvWCxh6Gn6fRbhXRmJUSOoK2E3jeC0upguUnBQm/OLkzSygHF1CqeHVc+9ONSlgDk6911abjFR00IRidz6iSfEdlE0HPeJznJIDZEmZr061qlPWx6Tj73p/41Fdr1Dyn0PDird17UgZJgFWJ67jS+fcNWWDilUSBr18Oq4iYafziTV9mQK+X/HzAUpUJdAG59+N/ihSb1MeIwApjcKgG9SIDC9NpHo9y2w1spr
      student-00-c13ac57de5dd@qwiklabs.net
  - key: enable-oslogin
    value: 'true'
  kind: compute#metadata
creationTimestamp: '2023-12-25T15:51:09.161-08:00'
defaultNetworkTier: PREMIUM
defaultServiceAccount: 797165076231-compute@developer.gserviceaccount.com
id: '6157414755346131843'
kind: compute#project
name: qwiklabs-gcp-01-ffab54b71b55
quotas:
- limit: 1000.0
  metric: SNAPSHOTS
  usage: 0.0
- limit: 5.0
  metric: NETWORKS
  usage: 1.0
- limit: 100.0
  metric: FIREWALLS
  usage: 4.0
- limit: 100.0
  metric: IMAGES
  usage: 0.0
- limit: 8.0
  metric: STATIC_ADDRESSES
  usage: 0.0
- limit: 200.0
  metric: ROUTES
  usage: 0.0
- limit: 15.0
  metric: FORWARDING_RULES
  usage: 0.0
- limit: 50.0
  metric: TARGET_POOLS
  usage: 0.0
- limit: 50.0
  metric: HEALTH_CHECKS
  usage: 0.0
- limit: 4.0
  metric: IN_USE_ADDRESSES
  usage: 0.0
- limit: 50.0
  metric: TARGET_INSTANCES
  usage: 0.0
- limit: 10.0
  metric: TARGET_HTTP_PROXIES
  usage: 0.0
- limit: 10.0
  metric: URL_MAPS
  usage: 0.0
- limit: 50.0
  metric: BACKEND_SERVICES
  usage: 0.0
- limit: 100.0
  metric: INSTANCE_TEMPLATES
  usage: 0.0
- limit: 5.0
  metric: TARGET_VPN_GATEWAYS
  usage: 0.0
- limit: 10.0
  metric: VPN_TUNNELS
  usage: 0.0
- limit: 3.0
  metric: BACKEND_BUCKETS
  usage: 0.0
- limit: 10.0
  metric: ROUTERS
  usage: 0.0
- limit: 10.0
  metric: TARGET_SSL_PROXIES
  usage: 0.0
- limit: 10.0
  metric: TARGET_HTTPS_PROXIES
  usage: 0.0
- limit: 10.0
  metric: SSL_CERTIFICATES
  usage: 0.0
- limit: 100.0
  metric: SUBNETWORKS
  usage: 0.0
- limit: 10.0
  metric: TARGET_TCP_PROXIES
  usage: 0.0
- limit: 12.0
  metric: CPUS_ALL_REGIONS
  usage: 0.0
- limit: 0.0
  metric: SECURITY_POLICIES
  usage: 0.0
- limit: 0.0
  metric: SECURITY_POLICY_RULES
  usage: 0.0
- limit: 1000.0
  metric: XPN_SERVICE_PROJECTS
  usage: 0.0
- limit: 20.0
  metric: PACKET_MIRRORINGS
  usage: 0.0
- limit: 100.0
  metric: NETWORK_ENDPOINT_GROUPS
  usage: 0.0
- limit: 6.0
  metric: INTERCONNECTS
  usage: 0.0
- limit: 5000.0
  metric: GLOBAL_INTERNAL_ADDRESSES
  usage: 0.0
- limit: 5.0
  metric: VPN_GATEWAYS
  usage: 0.0
- limit: 100.0
  metric: MACHINE_IMAGES
  usage: 0.0
- limit: 0.0
  metric: SECURITY_POLICY_CEVAL_RULES
  usage: 0.0
- limit: 0.0
  metric: GPUS_ALL_REGIONS
  usage: 0.0
- limit: 5.0
  metric: EXTERNAL_VPN_GATEWAYS
  usage: 0.0
- limit: 1.0
  metric: PUBLIC_ADVERTISED_PREFIXES
  usage: 0.0
- limit: 10.0
  metric: PUBLIC_DELEGATED_PREFIXES
  usage: 0.0
- limit: 128.0
  metric: STATIC_BYOIP_ADDRESSES
  usage: 0.0
- limit: 10.0
  metric: NETWORK_FIREWALL_POLICIES
  usage: 0.0
- limit: 15.0
  metric: INTERNAL_TRAFFIC_DIRECTOR_FORWARDING_RULES
  usage: 0.0
- limit: 15.0
  metric: GLOBAL_EXTERNAL_MANAGED_FORWARDING_RULES
  usage: 0.0
- limit: 50.0
  metric: GLOBAL_INTERNAL_MANAGED_BACKEND_SERVICES
  usage: 0.0
- limit: 50.0
  metric: GLOBAL_EXTERNAL_MANAGED_BACKEND_SERVICES
  usage: 0.0
- limit: 50.0
  metric: GLOBAL_EXTERNAL_PROXY_LB_BACKEND_SERVICES
  usage: 0.0
- limit: 100.0
  metric: GLOBAL_INTERNAL_TRAFFIC_DIRECTOR_BACKEND_SERVICES
  usage: 0.0
selfLink: https://www.googleapis.com/compute/v1/projects/qwiklabs-gcp-01-ffab54b71b55
vmDnsSetting: ZONAL_ONLY
xpnProjectStatus: UNSPECIFIED_XPN_PROJECT_STATUS
student_00_c13ac57de5dd@cloudshell:~ (qwiklabs-gcp-01-ffab54b71b55)$ export PROJECT_ID=$(gcloud config get-value project)
Your active configuration is: [cloudshell-19351]
student_00_c13ac57de5dd@cloudshell:~ (qwiklabs-gcp-01-ffab54b71b55)$ export ZONE=$(gcloud config get-value compute/zone)
Your active configuration is: [cloudshell-19351]
student_00_c13ac57de5dd@cloudshell:~ (qwiklabs-gcp-01-ffab54b71b55)$ echo -e "PROJECT ID: $PROJECT_ID\nZONE: $ZONE"
PROJECT ID: qwiklabs-gcp-01-ffab54b71b55
ZONE: us-central1-c
student_00_c13ac57de5dd@cloudshell:~ (qwiklabs-gcp-01-ffab54b71b55)$ gcloud compute instances create gcelab2 --machine-type e2-medium --zone $ZONE
Created [https://www.googleapis.com/compute/v1/projects/qwiklabs-gcp-01-ffab54b71b55/zones/us-central1-c/instances/gcelab2].
NAME: gcelab2
ZONE: us-central1-c
MACHINE_TYPE: e2-medium
PREEMPTIBLE: 
INTERNAL_IP: 10.128.0.2
EXTERNAL_IP: 34.133.156.4
STATUS: RUNNING
student_00_c13ac57de5dd@cloudshell:~ (qwiklabs-gcp-01-ffab54b71b55)$ 