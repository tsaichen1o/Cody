Task 1. Create a Cloud SQL instance
From the Navigation menu (Navigation menu icon) click on SQL.

Click Create Instance.

Choose MySQL database engine.

Enter Instance ID as myinstance.

In the password field click on the Generate link and the eye icon to see the password. Save the password to use in the next section.

Select the database version as MySQL 8.

For Choose a Cloud SQL edition, select Enterprise edition.

For Preset choose Development (4 vCPU, 16 GB RAM, 100 GB Storage, Single zone).

Warning: if you choose a preset larger than Development, your project will be flagged and your lab will be terminated.
Set Region as us-east1.

Set the Multi zones (Highly available) > Primary Zone field as us-east1-c.

Click CREATE INSTANCE.

It might take a few minutes for the instance to be created. Once it is, you will see a green checkmark next to the instance name.

Click on the Cloud SQL instance. The SQL Overview page opens.
Test Completed Task

Click Check my progress to verify your performed task. If you have successfully created a Cloud SQL instance, you will see an assessment score.

Assessment Completed! Cloud SQL instance created. SQL instance name(s): ["myinstance"]
Create a Cloud SQL instance
Assessment Completed! Cloud SQL instance created. SQL instance name(s): ["myinstance"]
Test your understanding

Below is a true/false question to reinforce your understanding of this lab's concepts. Answer it to the best of your ability.


Instance ID is used to uniquely identify your instance within the project.
check
True
close
False

Task 2. Connect to your instance using the mysql client in Cloud Shell
In the Cloud Console, click the Cloud Shell icon in the upper right corner.
Click Continue.

At the Cloud Shell prompt, connect to your Cloud SQL instance by running the following:

gcloud sql connect myinstance --user=root
Copied!
Click Authorize.

Enter your root password when prompted. Note: The cursor will not move.

Press the Enter key when you're done typing.

You should now see the mysql prompt.

Task 3. Create a database and upload data
Create a SQL database called guestbook on your Cloud SQL instance:
CREATE DATABASE guestbook;
Copied!
Test completed task

Click Check my progress to verify your performed task. If you have successfully created a custom database on the Cloud SQL instance, you will see an assessment score.

Assessment Completed! Databse created successfully. Database name(s): ["guestbook"]
Create a database.
Assessment Completed! Databse created successfully. Database name(s): ["guestbook"]
Insert the following sample data into the guestbook database:
USE guestbook;
CREATE TABLE entries (guestName VARCHAR(255), content VARCHAR(255),
    entryID INT NOT NULL AUTO_INCREMENT, PRIMARY KEY(entryID));
    INSERT INTO entries (guestName, content) values ("first guest", "I got here!");
INSERT INTO entries (guestName, content) values ("second guest", "Me too!");
Copied!
Now retrieve the data:
SELECT * FROM entries;
Copied!
You should see:

+--------------+-------------------+---------+
| guestName    | content           | entryID |
+--------------+-------------------+---------+
| first guest  | I got here!       |       1 |
| second guest | Me too!           |       2 |
+--------------+-------------------+---------+
2 rows in set (0.00 sec)
mysql>
