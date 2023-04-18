
#include <iostream>
#include <vector>
using namespace std;

char supplementNoc(char noc){
    char result;
    if (noc == 'A') result = 'T';
    else if (noc == 'T') result = 'A';
    else if (noc == 'C') result = 'G';
    else if (noc == 'G') result = 'C';
    return result;
}

string supplementRna(string r){
    string supplememt;
    for (int i = 0; i < r.length(); i++){
        supplememt.push_back(supplementNoc(r[i]));
    }
    return supplememt;
}

class genome {
    private:
        string rna;
        string dna[2];
    public:
    // -----------------------------------------------   Rna Methods
        void smallMutationRna(char target, char replacement, int count){
            int len = rna.length();
            for (int i = 0; i < len && count > 0; i++){
                if (rna[i] == target){
                    rna[i] = replacement;
                    count--;
                } else continue;
            }
        }
        void bigMutationRna(string target, string replacement){
            int full_len = rna.length();
            int tlen = target.length();
            int index;
            string result;
            for (int i = 0; i <= full_len - tlen; i++){
                if (rna[i] == target[0]){
                    string current;
                    for (int j = 0; j < tlen; j++){
                        current.push_back(rna[i + j]);
                    }
                    if (current == target){
                        index = i;
                        break;
                    }
                }
            }
            for (int i = 0; i < full_len - (tlen - replacement.length()); i++){
                if (i < index) result.push_back(rna[i]);
                else if (i >= index && i < index + replacement.length()) result.push_back(replacement[i - index]);
                else result.push_back(rna[i + (tlen - replacement.length())]);
            }
            rna = result;
        }
        void reversedMutationRna(string target){
            int index;
            int full_len = rna.length();
            int tlen = target.length();
            for (int i = 0; i <= full_len - tlen; i++){
                if (target[0] == rna[i]){
                    string current;
                    for (int j = 0; j < tlen; j++) current.push_back(rna[i + j]);
                    if (current == target){
                        index = i;
                        break;
                    }
                }
            }
            string result;
            for (int i = 0; i < full_len; i++){
                if (i < index) result.push_back(rna[i]);
                else if (i >= index && i < index + tlen) result.push_back(rna[tlen - (i - index) - 1]);
                else result.push_back(rna[i]);
            }
            rna = result;
        }
        string getRna(){
            return rna;
        }
        void setRna(string input){
            rna = input;
        }
        int getRnaLength(){
            return rna.length();
        }
        // ------------------------------------------------- Dna Methods
        string getRnaOfDna(int index = 0){
            string result;
            if (index == 0) result = dna[index];
            else if (index == 1) result = dna[index];
            else result = dna[0];
            return result;
        }
        void setRnaForDna(string r){
            dna[0] = r;
            dna[1] = supplementRna(r);
        }
        void setRnaOfDnaManually(string r1, string r2){
            dna[0] = r1;
            dna[1] = r2;
        }
        void smallMutationDna(char target, char replacement, int count){
            int len = dna[0].length();
            for (int i = 0; i < len && count > 0; i++){
                if (dna[0][i] == target){
                    dna[0][i] = replacement;
                    dna[1][i] = supplementNoc(replacement);
                    count--;
                } else if (dna[1][i] == target){
                    dna[1][i] = replacement;
                    dna[0][i] = supplementNoc(replacement);
                    count--;
                } else continue;
            }
        }
        void bigMutationDna(string target, string replacement){
            int full_len = dna[0].length();
            int tlen = target.length();
            int index;
            string result1, result2;
            int group = -1;
            for (int i = 0; i <= full_len - tlen; i++){
                if (target[0] == dna[0][i]){
                    string current;
                    for (int j = 0; j < tlen; j++){
                        current.push_back(dna[0][i + j]);
                    }
                    if (current == target){
                        group = 0;
                        index = i;
                        break;
                    }
                }
            }
            if (group == -1){
                for (int i = 0; i <= full_len - tlen; i++){
                    if (target[0] == dna[1][i]){
                        string current;
                        for (int j = 0; j < tlen; j++){
                            current.push_back(dna[1][i + j]);
                        }
                        if (current == target){
                            group = 1;
                            index = i;
                            break;
                        }
                    }
                }
            }
            if (group != -1){
                for (int i = 0; i < full_len - (tlen - replacement.length()); i++){
                    if (i < index){
                        result1.push_back(dna[0][i]);
                        result2.push_back(dna[1][i]);
                    }
                    else if (i >= index && i < index + replacement.length()){
                        if (group == 0){
                            result1.push_back(replacement[i - index]);
                            result2.push_back(supplementNoc(replacement[i - index]));
                        } else if (group == 1){
                            result1.push_back(supplementNoc(replacement[i - index]));
                            result2.push_back(replacement[i - index]);
                        }
                    }
                    else {
                        result1.push_back(dna[0][i + tlen - replacement.length()]);
                        result2.push_back(dna[1][i + tlen - replacement.length()]);
                    }
                }
            }
            dna[0] = result1;
            dna[1] = result2;
        }
        void reversedMutationDna(string target){
            int index;
            int tlen = target.length();
            int full_len = dna[0].length();
            for (int i = 0; i <= full_len - tlen; i++){
                if (dna[0][i] == target[0]){
                    index = i;
                    break;
                }
            }
            string result1, result2;
            for (int i = 0; i < full_len; i++){
                if (i < index) {
                    result1.push_back(dna[0][i]);
                    result2.push_back(dna[1][i]);
                }
                else if (i >= index && i < index + tlen) {
                    result1.push_back(target[tlen - (i - index) - 1]);
                    result2.push_back(supplementNoc(target[tlen - (i - index) - 1]));
                }
                else {
                    result1.push_back(dna[0][i]);
                    result2.push_back(dna[1][i]);
                }
            }
            
        }
        friend bool operator==(genome& krom1, genome& krom2){
            bool result = true;
            if (krom1.getRnaOfDna().length() == krom2.getRnaOfDna().length()){
                int len = krom1.getRnaOfDna().length();
                for (int i = 0; i < len; i++){
                    if (krom1.getRnaOfDna(0)[i] != krom2.getRnaOfDna(0)[i] || krom1.getRnaOfDna(1)[i] != krom2.getRnaOfDna(1)[i]){
                        result = false;
                        break;
                    }
                }
            }
            return result;
        }
};

class cell : public genome {
    private:
        vector<genome> kroms;
        int kromsCount;
    public:
        void addKrom(string r){
            genome result;
            result.setRnaForDna(r);
            kroms.push_back(result);
        }
        genome getKrom(int index){
            return kroms[index];
        }
        void editKrom(int index, string rna1, string rna2 = ""){
            genome k = getKrom(index);
            if (rna2 == "") k.setRnaForDna(rna1);
            else if (rna1.length() == rna2.length()) k.setRnaOfDnaManually(rna1, rna2);
            kroms[index] = k;
        }
        bool aliveKrom(int index){
            genome k = kroms[index];
            bool result = true;
            string firstString = k.getRnaOfDna(0);
            string secondString = k.getRnaOfDna(1);
            int problems = 0;
            for (int i = 0; i < firstString.length(); i++){
                if (firstString[i] != supplementNoc(secondString[i])) problems++;
                
            }
            if (problems > 5) result = false;
            if (result == true){
                int at = 0;
                int gc = 0;
                for (int i = 0; i < firstString.length(); i++){
                    if (firstString[i] == supplementNoc(secondString[i]) && (firstString[i] == 'A' || firstString[i] == 'T')){
                        at++;
                    } else if (firstString[i] == supplementNoc(secondString[i]) && (firstString[i] == 'G' || firstString[i] == 'C')){
                        gc++;
                    }
                }
                if (at > 3 * gc) result = false;
            }
            return result;
        }
        int kromCount(){
            return kroms.size();
        }
        vector<genome> getkroms(){
            return kroms;
        }

        // --------------------------- genome overridden fucnction : bigMutation
        void bigMutationDna(string target, int n, string replacement, int m){

            n--;
            m--;

            genome tKrom = kroms[n];
            genome rKrom = kroms[m];
            string firstKrom[2] = {tKrom.getRnaOfDna(0), tKrom.getRnaOfDna(1)};
            string secondKrom[2] = {rKrom.getRnaOfDna(0), rKrom.getRnaOfDna(1)};
            bool found1 = false, found2 = false;
            int index1, index2;

            // finding 1st index
            for (int i = 0; i <= firstKrom[0].length() - target.length(); i++){
                if (firstKrom[0][i] == target[0]){
                    string current;
                    for (int j = 0; j < target.length(); j++) current.push_back(firstKrom[0][i + j]);
                    if (target == current){
                        found1 = true;
                        index1 = i;
                        break;
                    }
                }
            }
            if (!found1){
                for (int i = 0; i <= firstKrom[1].length() - target.length(); i++){
                    if (firstKrom[1][i] == target[0]){
                        string current;
                        for (int j = 0; j < target.length(); j++) current.push_back(firstKrom[1][i + j]);
                        if (target == current){
                            found1 = true;
                            index1 = i;
                            break;
                        }
                    }
                }
            }

            // finding 2nd index 
            for (int i = 0; i <= secondKrom[0].length() - replacement.length(); i++){
                if (secondKrom[0][i] == replacement[0]){
                    string current;
                    for (int j = 0; j < replacement.length(); j++) current.push_back(secondKrom[0][i + j]);
                    if (replacement == current){
                        found2 = true;
                        index2 = i;
                        break;
                    }
                }
            }
            if (!found2){
                for (int i = 0; i <= secondKrom[1].length() - replacement.length(); i++){
                    if (secondKrom[1][i] == replacement[0]){
                        string current;
                        for (int j = 0; j < replacement.length(); j++) current.push_back(secondKrom[1][i + j]);
                        if (replacement == current){
                            found2 = true;
                            index2 = i;
                            break;
                        }
                    }
                }
            }

            int len1 = target.length(), len2 = replacement.length();
 
            // switching variables
            string result1[2], result2[2];
            for (int i = 0; i < firstKrom[0].length() - (len1 - len2); i++){
                if (i < index1){
                    result1[0].push_back(firstKrom[0][i]);
                    result1[1].push_back(firstKrom[1][i]);
                } else if (i >= index1 && i < index1 + len2){
                    result1[0].push_back(replacement[i - index1]);
                    result1[1].push_back(supplementNoc(replacement[i - index1]));
                } else {
                    result1[0].push_back(firstKrom[0][i - len1 + len2]);
                    result1[1].push_back(firstKrom[1][i - len1 + len2]);
                }
            }
            for (int i = 0; i < secondKrom[0].length() - (len2 - len1); i++){
                if (i < index2){
                    result2[0].push_back(secondKrom[0][i]);
                    result2[1].push_back(secondKrom[1][i]);
                } else if (i >= index2 && i < index2 + len1){
                    result2[0].push_back(target[i - index2]);
                    result2[1].push_back(supplementNoc(target[i - index2]));
                } else {
                    result2[0].push_back(secondKrom[0][i - len2 + len1]);
                    result2[1].push_back(secondKrom[1][i - len2 + len1]);
                }
            }
            kroms[n].setRnaOfDnaManually(result1[0], result1[1]);
            kroms[m].setRnaOfDnaManually(result2[0], result2[1]);
        }
        // ------------------- end of bigMutation

        void reversedMutation(string target, int n){
            string input1 = kroms[n - 1].getRnaOfDna(0);
            string input2 = kroms[n - 1].getRnaOfDna(1);
            int index;
            int full_len = input1.length();
            int tlen = target.length();
            for (int i = 0; i <= full_len - tlen; i++){
                if (target[0] == input1[i]){
                    string current;
                    for (int j = 0; j < tlen; j++) current.push_back(input1[i + j]);
                    if (current == target){
                        index = i;
                        break;
                    }
                }
            }
            string result1, result2;
            for (int i = 0; i < full_len; i++){
                if (i < index){
                    result1.push_back(input1[i]);
                    result2.push_back(input2[i]);
                } else if (i >= index && i < index + tlen){
                    result1.push_back(target[tlen - (i - index) - 1]);
                    result2.push_back(supplementNoc(target[tlen - (i - index) - 1]));
                } else {
                    result1.push_back(input1[i]);
                    result2.push_back(input2[i]);
                }
            }
            kroms[n - 1].setRnaOfDnaManually(result1, result2);
        }
        vector<string> findSupPalindroms(int index){
            int min = 4; // the minumum range
            int max = kroms[index].getRnaOfDna().length() - (kroms[index].getRnaOfDna().length() % 2); // the maximum range
            string input1 = kroms[index].getRnaOfDna(0), input2 = kroms[index].getRnaOfDna(1); // krom strings
            vector<string> result; // stores the results
            // i sets the range
            for (int i = min; i <= max; i += 2){
                // j sets the index
                for (int j = 0; j <= input1.length() - i; j++){
                    bool match = true;
                    string c1 = "", c2 = "";
                    // k operates the range
                    for (int k = 0; k < i / 2; k++) {
                        c1.push_back(input1[j + k]);
                    }
                    for (int k = i / 2; k < (i / 2) * 2; k++) {
                        c2.push_back(input1[j + k]);
                    }
                    for (int k = 0; k < i / 2; k++){
                        if (c1[k] != supplementNoc(c2[i / 2 - k - 1])){
                            match = false;
                            break;
                        }
                    }
                    if (match){
                        string r;
                        for (int k = 0; k < i; k++) r.push_back(input1[j + k]);
                        result.push_back(r);
                    }
                }
            }
            return result;
        }
        void removeKrom(int index){
            kroms.erase(kroms.begin() + (index + 1));
        }
};
