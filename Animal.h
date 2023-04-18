
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Cell.h"

using namespace std;

class animal: public cell{
    private:
        cell mainCell;
    public:
        int similarity(animal sample){
            vector<genome> fKroms = mainCell.getkroms();
            vector<genome> sKroms = sample.mainCell.getkroms();
            int flen = fKroms.size(), slen = sKroms.size();
            int count = 0;
            for (int i = 0; i < fKroms.size(); i++){
                for (int j = 0; j < sKroms.size(); j++){
                    if (fKroms[i] == sKroms[j]){
                        fKroms.erase(fKroms.begin() + i + 1);
                        sKroms.erase(sKroms.begin() + j + 1);
                        count++;
                        i = 0, j = 0;
                    }
                }
            }
            return (int) round(((float) count * 2 / ((float) flen + (float) slen)) * 100);
        }
        void addKrom(genome k){
            mainCell.addKrom(k.getRnaOfDna());
        }
        vector<genome> getAnimalKroms(){
            return mainCell.getkroms();
        }
        genome getAnimalKrom(int index){
            return mainCell.getKrom(index);
        }
        friend bool operator==(animal animal1, animal animal2){
            if (animal1.similarity(animal2) >= 70 && animal1.mainCell.kromCount() == animal2.mainCell.kromCount()) return true;
            else return false;
        }
        animal nonSexualReproduction(){
            srand(time(0));
            animal child;
            vector<genome> cellKroms = mainCell.getkroms();
            int len = cellKroms.size();
            int need = round(cellKroms.size() * 0.7);
            if (cellKroms.size() % 10 != 0) need++;
            for (int i = 0; i < need; i++){
                int random = rand() % cellKroms.size();
                child.addKrom(cellKroms[random]);
                vector<genome> kroms_copy = {};
                for (int j = 0; j < cellKroms.size(); j++) if (random != j) kroms_copy.push_back(cellKroms[j]);
                cellKroms = kroms_copy;
            }
            cellKroms = mainCell.getkroms();
            for (int i = 0; i < len - need; i++){
                int random = rand() % cellKroms.size();
                child.addKrom(cellKroms[random]);
            }
            return child;
        }
        friend animal operator+(animal &p1, animal &p2){
            animal child;
            srand(time(0));
            vector<genome> c1 = p1.nonSexualReproduction().getAnimalKroms(), c2 = p2.nonSexualReproduction().getAnimalKroms();
            if (c1.size() == c2.size() && c1.size() % 2 == 0 && p1 == p2){
                vector<genome> same = {}; // keeps the same kroms
                for (int i = 0; i < c1.size(); i++){
                    genome current = c1[i];
                    for (int j = 0; j < c2.size(); j++) if (current == c2[j]) same.push_back(current);
                }
                int need = round((c1.size() * 0.7) * 100);
                if (c1.size() % 10 != 0) need++;
                for (int i = 0; i < need && same.size() > 0; i++){
                    int random = rand() % same.size();
                    child.addKrom(same[random]);
                    vector<genome> same_copy = {};
                    for (int j = 0; j < same.size(); j++) if (j != random) same_copy.push_back(same[j]);
                    same = same_copy;
                }
                for (int i = 0; i < round(c1.size() - need) / 2 && c1.size() > 0; i++){
                    int random = rand() % c1.size();
                    child.addKrom(c1[random]);
                    vector<genome> kroms_copy = {};
                    for (int j = 0; j < c1.size(); j++) if (j != random) kroms_copy.push_back(c1[j]);
                    c1 = kroms_copy;
                }
                for (int i = 0; i < round(c2.size() - need) / 2 && c2.size() > 0; i++){
                    int random = rand() % c2.size();
                    child.addKrom(c2[random]);
                    vector<genome> kroms_copy = {};
                    for (int j = 0; j < c1.size(); j++) if (j != random) kroms_copy.push_back(c2[j]);
                    c2 = kroms_copy;
                }
                while (child.kromCount() > c1.size()) child.removeLastKrom(); // controlling size
            }
            return child;
        }
        bool aliveKrom(){
            bool result = true;
            for (int i = 0; i < mainCell.getkroms().size(); i++) if (!mainCell.aliveKrom(i)){
                mainCell.removeKrom(i);
                result = false;
            }
            return result;
        }
        void setCell(cell c){
            for (int i = 0; i < mainCell.kromCount(); i++) mainCell.removeKrom(i);
            for (int i = 0; i < c.kromCount(); i++) mainCell.addKrom(c.getKrom(i).getRnaOfDna());
        }
        bool emptyAnimal(){
            if (mainCell.kromCount() == 0) return true;
            else return false;
        }
        int cellKromCount(){
            return mainCell.kromCount();
        }
        void removeLastKrom(){
            mainCell.removeKrom(mainCell.kromCount() - 1);
        }
};
