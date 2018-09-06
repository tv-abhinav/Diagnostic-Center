# Diagnostic-Center
Contains the source code for a "Diagnostic Center management" submitted for TCS Insight
There are 2 types of user: Doctor and Administrative officer
The system should maintain a doctor register and a patients register. User should be able to perform following operations:
 For managing doctors: (Access is given for Administrative officers only)
1.	Add a new doctor

Each doctor should have the following details:
a.	Name
b.	Title (Master Health Check up, Hepatitis B & C tests, Allergy Testing, Osteoporosis scan)
c.	Gender
d.	Date of Birth
e.	Qualification
f.	Medical License No.
g.	Center Id
h.	Address 
i.	Contact number
j.	Email id

2.	Search on Medical License No./ Center Id
3.	Search on Name/Contact number
4.	Modify the doctor details
5.	Add a new title
  
For managing patients: (Access is given for Doctor and Administrative officers)
1.	Add a new patient. 

Each patient should have the following details:
a.	Registration Number
b.	Registration Date
c.	Name
d.	Gender
e.	Date of Birth
f.	Address
g.	Contact phone number
h.	 Hospital Referred by
i.	Test Date
j.	Test Type (X-ray/ECG/CT Scan/MRI Scan/Cardiac CT)
k.	 Doctor’s Name: 
l.	 Fees

2.	Add more tests for the same patient. 
3.	Modify patient details.
4.	Search on Registration number.
5.	Search on patient name/phone number.

Add any other data/info for doctors & patients if required. Store the doctor & patient data in a flat file. When the system is started, it should fetch the patient data from this flat file. At the end, the system should update the modified data in the same flat file. 
