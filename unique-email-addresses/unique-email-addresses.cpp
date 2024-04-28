class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        
        unordered_set<string> uniqueEmails;

        for (const string& email : emails) {
            // find the position of '@'
            size_t atPos = email.find('@');
            // split into two parts: local and domain
            string local = email.substr(0, atPos);
            string domain = email.substr(atPos);
 
            // split local by '+'
            size_t plusPos = local.find('+');
            if (plusPos != string::npos) local = local.substr(0, plusPos);
            

            // remove all '.' append domain
            string processedEmail = "";
            for (char c : local) {
                if (c != '.')  processedEmail += c;
            }
            processedEmail += domain;

            // add the processed email to the set
            uniqueEmails.insert(processedEmail);
        }

        return uniqueEmails.size();
    }
};