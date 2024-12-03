#Q1
def encryption(text,skey):
    st=""
    for i in range(0,len(text)):
        if ord(text[i])>=65 and ord(text[i])<=90:
            num=ord(text[i])+skey
            if(num>90):
                num-=26
            st+=chr(num)
        elif ord(text[i])>=97 and ord(text[i])<=122:
            num=ord(text[i])+skey
            if(num>122):
                num-=26
            st+=chr(num)
        else:
            st+=text[i]
    return st



def decryption(text,skey):
    st=""
    for i in range(0,len(text)):
        if ord(text[i])>=65 and ord(text[i])<=90:
            num=ord(text[i])-skey
            if(num<65):
                num+=26
            st+=chr(num)
        elif ord(text[i])>=97 and ord(text[i])<=122:
            num=ord(text[i])- skey
            if(num<97):
                num+=26
            st+=chr(num)
        else:
            st+=text[i]
        
    return st



while True:
    print("MENU")
    print("1. Encryption")
    print("2. Decryption")
    print("3. Exit")

    ch=input("Enter your choice: ")
    if ch=="1":
        text=input("Enter your text: ")
        sk=int(input("Enter the shift key: "))
        result=encryption(text,sk)
        print("Encrypted text is: ",result)
        
    elif ch=="2":
        text=input("Enter your encrypted text: ")
        sk=int(input("Enter the shift key: "))
        result=decryption(text,sk)
        print("Decrypted text is: ",result)
        
    elif ch=="3":
        break
    else:
        print("Invalid choice")



#Q2
def encryptRailFence(text, key): 
 rail = [['\n' for i in range(len(text))] 
    for j in range(key)] 
 dir_down = False 
 row, col = 0, 0 
  
 for i in range(len(text)): 
  if (row == 0) or (row == key - 1): 
   dir_down = not dir_down 
  rail[row][col] = text[i] 
  col += 1 
  if dir_down: 
   row += 1 
  else: 
   row -= 1 
 result = [] 
 for i in range(key): 
  for j in range(len(text)): 
   if rail[i][j] != '\n': 
    result.append(rail[i][j]) 
 return("" . join(result)) 
  
def decryptRailFence(cipher, key): 
 
 rail = [['\n' for i in range(len(cipher))] 
    for j in range(key)] 
 dir_down = None 
 row, col = 0, 0 
  
 # mark the places with '*' 
 for i in range(len(cipher)): 
  if row == 0: 
   dir_down = True 
  if row == key - 1: 
   dir_down = False 
   
  # place the marker 
  rail[row][col] = '*' 
  col += 1 
   
  # find the next row 
  # using direction flag 
  if dir_down: 
   row += 1 
  else: 
   row -= 1 
    
 index = 0 
 for i in range(key): 
  for j in range(len(cipher)): 
   if ((rail[i][j] == '*') and 
   (index < len(cipher))): 
    rail[i][j] = cipher[index] 
    index += 1 
 result = [] 
 row, col = 0, 0 
 for i in range(len(cipher)): 
  if row == 0: 
   dir_down = True 
  if row == key-1: 
   dir_down = False 
  if (rail[row][col] != '*'): 
   result.append(rail[row][col]) 
   col += 1 
  if dir_down: 
   row += 1 
  else: 
   row -= 1 
 return("".join(result)) 
 
if __name__ == "__main__": 
    print("The Encrypted text is: ") 
    print(encryptRailFence("attack at once", 2)) 
    print("The Decrypted text is: ") 
    print(decryptRailFence("atc toctaka ne", 2))

#Q3
 import rsa
 message=b'this is our text to hash'
 message
 #b'this is our text to hash'
 htext=rsa.compute_hash(message,'SHA-256')
 htext #this is byte format so changing it into hex in next line
 #b'\xa5\x80F\xa6\xdbAj\xe9\xe4\xd8\xae\x0f\xb6\x0e\xce\xe0\xf0\xcfK\x19k\x184\x8d\xda\xdd\x0e}|\xdf8+'
 hashed_value=htext.hex()
 print(hashed_value)
# a58046a6db416ae9e4d8ae0fb60ecee0f0cf4b196b18348ddadd0e7d7cdf382b
 len(hashed_value)
 #64

#Q4
import hashlib
import requests

#Reading the usernames and passwords from passwords.txt 
def read_user_data(file_name):
    users=[]
    with open(file_name,"r") as file:
        for line in file:
            username,password=line.strip().split(',')
            users.append((username,password))
    return users

#Hashing the password using SHA-1
def hash_password(password):
    h=hashlib.sha1(password.encode('utf-8')).hexdigest().upper()
    return h

#Checking if the password is leaked or not
def check_password_leak(password_hash):
    prefix=password_hash[:5]
    suffix=password_hash[5:]

    url=f"https://api.pwnedpasswords.com/range/{prefix}"
    response=requests.get(url)

    if response.status_code!=200:
        raise RuntimeError(f"Error fetching data from HIBP API: {response.status_code}")
    hashes=(line.split(':') for line in response.text.splitlines())
    for hash_suffix,count in hashes:
        if hash_suffix == suffix:
            return True, count
    return False, 0

def main(file_name):
    users=read_user_data(file_name)
    for username, password in users:
        password_hash=hash_password(password)
        leaked, count=check_password_leak(password_hash)
        if leaked:
            print(f"[Warning] Password for user '{username}' has been leaked {count} times.")
        else:
            print(f"Password for user '{username}' is safe.")

main("passwords.txt")
    
    
    





#Q5
import random
def generate_password():
    words=[]
    with open("dictionary.txt","r") as file:
        for line in file:
            words=line.split()
    selected_words=random.sample(words,6)
    for i in range(0,len(selected_words),2):
        selected_words[i]=selected_words[i].capitalize()
    for i in range(len(selected_words)):
        special_char=random.choice(['-','@','#','%','.','!'])
        selected_words[i]+=special_char 
    password=''.join(selected_words)
    password+=str(random.randint(10,99))
    print(password)

print("Some Passwords are: ")
for i in range(8):
    generate_password()


#Q6
import itertools
import time

characters = 'abcdefghijklmnopqrstuvwxyz0123456789@#%.,&'
correct_password = 'a1#'

def brute_force_attack(charset, max_length, target_password):
    start_time = time.time()
    for length in range(1, max_length + 1):
        for guess in itertools.product(charset, repeat=length):
            guess_password = ''.join(guess)
            print(f'Trying: {guess_password}')
            
            if guess_password == target_password:
                elapsed_time = time.time() - start_time
                print(f"Password '{guess_password}' found in {elapsed_time:.2f} seconds.")
                return guess_password
    return None

brute_force_attack(characters, 5, correct_password)

#Q8
"""
Data Privacy Audit Report 
Organization: EpicPlay Ltd.  (A Gaming Company) 
Audit Period: July 1, 2024 – July 31, 2024 
1. Scope Definition 
• Objective: To assess EpicPlay Ltd.'s compliance with GDPR, focusing on data collection, 
storage, processing, security, and user rights within their gaming platform. 
• Scope: Review of data handling across player accounts, in-game data, marketing 
communications, third-party integrations, and data storage and deletion practices within the 
gaming platform. 
• Methodology: Data flow mapping, policy documentation review, and stakeholder interviews 
within the IT, marketing, and customer service teams. 
2. Policies and Procedure Review 
• Data Protection Policy: EpicPlay has a basic data protection policy covering general data 
handling, but it lacks specific guidelines for data retention and encryption requirements. 
• Consent Policy: Consent practices are unclear regarding data used for analytics and 
advertising. 
• Recommendations: Develop detailed policies for data retention and encryption. Update the 
consent policy to specify data usage in analytics, ads, and targeted marketing. 
3. Compliance Assessment 
• Applicable Regulations: GDPR as the primary regulation, given the EU user base. 
• Compliance Status: Partially compliant with GDPR requirements, with critical gaps in data 
retention, consent practices, and third-party agreements. 
• Recommendations: Update data handling policies to fully align with GDPR and conduct 
regular compliance reviews. 
4. Data Inventory and Classification 
• Data Collected: 
o Player Account Data: Username, email, IP address, age. 
o Gameplay Data: Game progress, achievements, in-game communications. 
o Payment Data: Processed by a third-party payment provider, including transaction 
history and payment method. 
• Data Classification: Personal data, including both identifiable (email, IP) and sensitive (billing 
information) data categories. 
• Recommendations: Maintain a regularly updated data inventory, classifying data by 
sensitivity and retention requirements. 
5. Access Controls Review 
• Observation: Player data is widely accessible to customer support and marketing teams, with 
no automated logging of access. 
• Access Management: Lack of role-based access controls (RBAC) and no consistent logging of 
data access. 
• Recommendations: Implement RBAC, restricting data access to essential personnel only, and 
deploy access logging to track and audit data usage. 
6. Security Measures Assessment 
• Encryption: Currently applied only to payment data. 
• Incident Response Plan: Exists but has not been updated to meet GDPR's data breach 
response requirements. 
• Recommendations: Extend encryption to cover all player data. Update the incident response 
plan to align with GDPR’s 72-hour breach notification requirement. 
7. Third-Party Risk Assessment 
• Third-Party Data Processors: EpicPlay partners with analytics and payment providers but 
lacks comprehensive Data Processing Agreements (DPAs). 
• Risk of Non-Compliance: High, due to gaps in data protection clauses within third-party 
contracts. 
• Recommendations: Revise third-party contracts to include GDPR-compliant DPAs and ensure 
vendors have robust data protection measures. 
8. Training and Awareness 
• Current Status: Employees have minimal training on GDPR requirements and data privacy 
practices. 
• Observation: Limited awareness of data handling risks and GDPR rights among customer 
support and marketing teams. 
• Recommendations: Implement a data privacy training program focusing on GDPR 
compliance, access control, and data breach protocols for all relevant staff. 
9. Incident History Review 
• Previous Incidents: No data breaches reported, though minor unauthorized access incidents 
occurred, likely due to poor access controls. 
• Incident Response Evaluation: Response was manual and lacked proper documentation. 
• Recommendations: Formalize incident documentation procedures and conduct regular 
response drills to improve readiness. 
10. Risk Assessment and Reporting 
• Risk Level: High 
• Key Risks: 
o Lack of data retention policy for inactive player accounts. 
o Poor access controls, exposing sensitive data to non-essential personnel. 
o Limited third-party data protection measures. 
• Recommendations: Prioritize data retention policies, improve access management, and 
address third-party data protection gaps. Establish quarterly risk assessment and reporting to 
monitor compliance. 
11. Follow-Up and Continuous Improvement 
• Action Items: 
o Implement role-based access controls and access logging – Target Completion: 
August 15, 2024. 
o Revise consent collection practices for better transparency – Target Completion: 
August 30, 2024. 
o Establish data retention policies and communicate them to players – Target 
Completion: September 15, 2024. 
o Amend third-party contracts to include DPAs – Target Completion: September 30, 
2024. 
o Establish a player data request portal for automated data management – Target 
Completion: October 15, 2024. 
• Ongoing Review: Schedule bi-annual audits and regular monitoring to ensure compliance as 
data protection standards evolve.

"""

#Q9

"""
Q9.  Students need to explore the requirements of the Data 
Protection Regulations and develop a plan for ensuring compliance 
with the regulation.  
To ensure compliance with Data Protection Regulations, organizations must understand the 
core requirements and develop a structured plan that addresses each aspect of the 
regulation. Here’s a comprehensive outline of the key requirements and a compliance plan: 
1. Overview of Data Protection Regulations 
Data Protection Regulations, such as the General Data Protection Regulation (GDPR) in the 
EU or similar standards worldwide, mandate the responsible management of personal data. 
They aim to protect individual rights, enhance transparency, and strengthen accountability in 
handling data. Non-compliance can lead to severe penalties and reputational damage. 
2. Key Requirements of Data Protection Regulations 
A. Lawfulness, Fairness, and Transparency 
Organizations must process personal data legally and transparently, ensuring data subjects 
understand how their data is used. Consent must be obtained explicitly, with clear 
information on data collection, usage, and sharing. 
B. Purpose Limitation 
Data should be collected for specific, legitimate purposes and not processed in a manner 
incompatible with those purposes. 
C. Data Minimization 
Only data necessary for the intended purpose should be collected. This minimizes risks 
associated with data exposure and ensures efficient processing. 
D. Accuracy 
Data controllers must ensure the accuracy of personal data, updating or correcting data 
when necessary to avoid incorrect information. 
E. Storage Limitation 
Data should be stored only as long as required for its intended purpose. Regular reviews and 
data deletion policies are essential for maintaining compliance. 
F. Integrity and Confidentiality 
Appropriate technical and organizational measures must be in place to secure personal data 
against unauthorized access, alteration, or loss. 
G. Accountability 
Organizations must be able to demonstrate compliance with the regulation through 
documented policies, procedures, and ongoing monitoring. 
3. Compliance Plan for Data Protection 
To achieve compliance with data protection regulations, organizations should adopt the 
following structured plan: 
Step 1: Conduct a Data Audit 
• Objective: Identify and catalog all personal data collected, processed, and stored. 
• Actions: 
o Document types of personal data and their processing methods. 
o Identify data sources, data-sharing parties, and storage locations. 
o Assess the necessity of each data element concerning its processing purpose. 
Step 2: Establish Data Collection Policies 
• Objective: Limit data collection to only what is necessary and lawful. 
• Actions: 
o Define the purpose for each data collection effort. 
o Implement informed consent mechanisms with easy opt-in/out options. 
o Regularly review data collection practices and ensure data subjects are 
informed of any changes. 
Step 3: Implement Access Controls and Security Measures 
• Objective: Protect data integrity and confidentiality. 
• Actions: 
o Use role-based access controls to limit data access to authorized personnel 
only. 
o Implement encryption, firewalls, and intrusion detection systems for data 
storage and transfer. 
o Conduct regular security audits and vulnerability assessments. 
Step 4: Create a Data Retention and Disposal Policy 
• Objective: Ensure data is stored only as long as necessary and securely disposed of 
when no longer needed. 
• Actions: 
o Define retention periods based on regulatory requirements and business 
needs. 
o Automate data deletion for expired data and provide secure disposal 
methods (e.g., secure shredding or digital wiping). 
Step 5: Train Employees on Data Protection 
• Objective: Build a culture of data protection awareness. 
• Actions: 
o Conduct regular training sessions on data protection principles and specific 
compliance practices. 
o Educate employees on recognizing data breaches and reporting them 
promptly. 
o Create a data protection manual for reference and best practices. 
Step 6: Develop Incident Response and Breach Notification Procedures 
• Objective: Quickly detect, respond to, and report data breaches. 
• Actions: 
o Establish an incident response team and a detailed response plan. 
o Ensure compliance with notification requirements by notifying affected 
parties within the stipulated time frame (e.g., within 72 hours for GDPR). 
o Regularly test and update the incident response plan. 
Step 7: Appoint a Data Protection Officer (DPO) 
• Objective: Oversee compliance efforts and act as a point of contact with data 
protection authorities. 
• Actions: 
o Designate a DPO responsible for ensuring compliance, training, and handling 
data subject requests. 
o Ensure the DPO has the autonomy and resources to perform duties 
effectively. 
o Regularly report compliance updates and potential risks to top management. 
Step 8: Monitor Compliance and Regularly Review Policies 
• Objective: Continuously assess and improve data protection practices. 
• Actions: 
o Conduct periodic compliance assessments, particularly after changes in data 
processing practices or regulations. 
o Update policies to address evolving regulatory requirements and business 
practices. 
o Encourage feedback from stakeholders and data subjects to improve data protection 
measures. 
4. Conclusion 
Effective compliance with Data Protection Regulations requires an organization-wide 
commitment to data security, privacy, and accountability. By following these steps, 
organizations can significantly reduce risks associated with data breaches, build trust with 
their customers, and demonstrate regulatory responsibility.
"""


#Q10
"""  
Q10.  You need to explore ethical considerations in data privacy, 
such as the balance between privacy and security, the impact of data 
collection and analysis on marginalized communities, and the role of 
data ethics in technology development. 
Data privacy is a critical ethical issue in today's digital world, where data is 
collected, stored, and analysed on an unprecedented scale. Ethical 
considerations in data privacy go beyond mere compliance with regulations; 
they encompass the moral principles that guide how data is used, how people’s 
rights are respected, and how societal values are upheld. Here’s an exploration 
of key ethical considerations, covering the balance between privacy and 
security, impacts on marginalized communities, and the role of data ethics in 
technology development. 
1. Balancing Privacy and Security 
The balance between individual privacy and societal security is a longstanding 
ethical challenge, heightened by the digital age. Security often requires some 
form of data access and monitoring to protect against threats like cyberattacks, 
terrorism, or fraud. However, excessive data collection or surveillance can 
infringe on personal privacy, leading to potential misuse or overreach. 
Key Ethical Questions: 
• What Level of Surveillance is Justifiable? Collecting data for security 
purposes must be done within limits that respect individual privacy. For 
example, while governments or corporations may collect data to ensure 
public safety, there must be checks in place to prevent overreach, 
unnecessary surveillance, or profiling. 
• Transparency and Consent: Individuals have a right to know how their 
data is used for security purposes. Transparent data practices, where 
users are informed and can consent to specific uses, help create trust 
and clarify the boundaries of data use. 
• Data Minimization and Anonymization: Security measures should 
collect only the minimum necessary data and, when possible, anonymize 
it to protect privacy. This approach maintains the effectiveness of 
security measures while minimizing risks to individual privacy. 
Balancing these factors requires policies that prioritize both security and 
privacy without sacrificing one for the other. Ethical frameworks and 
regulations should address this balance to provide clear guidelines for both 
private companies and governments. 
2. Impact of Data Collection on Marginalized Communities 
Data collection and analysis can disproportionately impact marginalized 
communities, often exacerbating existing inequalities. Vulnerable groups, such 
as ethnic minorities, low-income individuals, or those with less access to 
technology, may face unique privacy risks that need special consideration. 
Ethical Issues Affecting Marginalized Communities: 
• Bias and Discrimination in Data Use: Data used in predictive algorithms, 
such as those for hiring, credit scoring, or law enforcement, can contain 
biases that harm marginalized groups. For instance, historical data 
reflecting systemic discrimination can reinforce negative stereotypes or 
lead to unfair outcomes. 
• Informed Consent Challenges: Marginalized communities may face 
difficulties in understanding complex privacy policies, particularly when 
language barriers or limited digital literacy are involved. They may not be 
fully informed about data collection practices or understand the risks 
involved. 
• Privacy Risks with Location and Behavior Tracking: Collecting data about 
people’s locations, browsing habits, and behaviors may 
disproportionately affect those in low-income or marginalized 
communities. For instance, tracking data could reveal patterns that 
expose individuals to targeted policing or surveillance, even if they are 
not engaged in criminal activities. 
Steps for Ethical Data Practices: 
• Inclusive Data Policies: Develop data policies that protect marginalized 
groups by ensuring fair representation, minimizing biased data usage, 
and creating clear consent mechanisms. 
• Community Engagement: Involve marginalized communities in 
discussions about data policies that affect them. This inclusive approach 
ensures that the specific needs, perspectives, and risks for these 
communities are considered. 
• Bias Audits and Ethical Testing: Conduct regular bias audits on 
algorithms to detect and mitigate potential discrimination. Implementing 
fairness and accountability checks can prevent biased outcomes and 
ensure fair treatment for all individuals. 
3. The Role of Data Ethics in Technology Development 
Data ethics is an emerging field focused on guiding the responsible use of data 
in technology. As technologies like AI, machine learning, and big data analytics 
increasingly shape modern society, it’s essential that they are built on ethical 
principles that respect privacy, fairness, and accountability. 
Core Principles of Data Ethics in Technology Development: 
• Respect for Privacy and Autonomy: Ethical technology development 
prioritizes user privacy, giving individuals control over their data. This 
includes robust consent mechanisms, allowing users to opt out and 
providing them with clear options to manage their data preferences. 
• Transparency and Accountability: Data-driven technologies should 
operate transparently, explaining how data is collected, stored, and 
analyzed. Organizations should be accountable for the ethical use of 
data, with mechanisms to address errors, biases, or misuse. 
• Fairness and Non-discrimination: Data ethics emphasize the need for 
fairness and non-discrimination, especially when technologies influence 
critical decisions like hiring, healthcare, or education. Ensuring 
algorithms and data sources are unbiased is essential to avoid 
perpetuating societal inequalities. 
Promoting Ethical Data Use in Technology: 
• Ethics by Design: Ethical considerations should be integrated into the 
early stages of technology design and development. “Ethics by design” 
means embedding privacy and fairness safeguards into the technology 
itself, reducing the risk of harm. 
• Independent Ethical Committees: Organizations should consider 
establishing independent ethics committees to oversee data use and 
technology development. These committees can provide impartial 
oversight and recommend improvements, especially when ethical 
concerns arise. 
• Long-term Impact Assessment: Before deploying new technologies, 
developers should assess potential long-term societal impacts, such as 
how data collection may shape user behaviour, influence public opinion, 
or affect marginalized communities. This forward-looking approach can 
help identify risks and guide responsible technology use. 
4. Conclusion: Building an Ethical Framework for Data Privacy 
Ethical considerations in data privacy require an organization-wide 
commitment to respecting individuals’ rights, ensuring fairness, and protecting 
vulnerable communities. This commitment involves: 
• Regularly updating policies to align with new ethical standards and 
societal expectations. 
• Educating employees on ethical data handling, privacy practices, and the 
broader impacts of data misuse. 
• Actively engaging with affected communities and stakeholders to gain 
insights and foster trust. 
By building data-driven systems on a foundation of ethics, organizations can 
create technologies that respect privacy, minimize harm, and contribute 
positively to society.
"""
