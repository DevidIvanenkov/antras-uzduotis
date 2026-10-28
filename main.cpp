#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_STUDENTS = 100;
const int MAX_GRADES = 10;

int main() {
    string names[MAX_STUDENTS];
    int grades[MAX_STUDENTS][MAX_GRADES];
    int gradeCounts[MAX_STUDENTS] = {0};
    int studentCount = 0;
    int choice;

    do {
        cout << "\n--- MOKINIU PAZYMIU SISTEMA ---\n";
        cout << "1. Ivesti mokini ir jo pazymius.\n";
        cout << "2. Perziureti visu mokiniu pazymius.\n";
        cout << "3. Perziureti konkretaus mokinio pazymius.\n";
        cout << "4. Atnaujinti pazymi.\n";
        cout << "5. Apskaiciuoti mokinio vidurki.\n";
        cout << "6. Pasalinti mokini.\n";
        cout << "7. Iseiti.\n";
        cout << "Pasirinkite veiksma (1-7): ";

        if (!(cin >> choice)) {
            cout << "Neteisinga ivestis.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                if (studentCount >= MAX_STUDENTS) {
                    cout << "Pasiektas limitas.\n";
                    break;
                }
                cout << "Vardas: ";
                cin >> names[studentCount];

                int gCount;
                cout << "Kiek pazymiu (iki 10)? ";
                cin >> gCount;
                while (gCount < 1 || gCount > MAX_GRADES) {
                    cout << "Neteisinga. Iveskite nuo 1 iki 10: ";
                    cin >> gCount;
                }

                gradeCounts[studentCount] = gCount;
                cout << "Iveskite pazymius (1-10):\n";
                for (int i = 0; i < gCount; i++) {
                    cin >> grades[studentCount][i];
                    while (grades[studentCount][i] < 1 || grades[studentCount][i] > 10) {
                        cout << "Neteisingas pazymys, bandykite vėl: ";
                        cin >> grades[studentCount][i];
                    }
                }
                studentCount++;
                cout << "Prideta!\n";
                break;
            }
            case 2: {
                if (studentCount == 0) {
                    cout << "Nera mokiniu.\n";
                    break;
                }
                for (int i = 0; i < studentCount; i++) {
                    cout << i + 1 << ". " << names[i] << " - Pazymiai: ";
                    for (int j = 0; j < gradeCounts[i]; j++) {
                        cout << grades[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            }
            case 3: {
                if (studentCount == 0) {
                    cout << "Nera mokiniu.\n";
                    break;
                }
                int sNum;
                cout << "Mokinio numeris (1-" << studentCount << "): ";
                cin >> sNum;
                if (sNum < 1 || sNum > studentCount) {
                    cout << "Neteisingas numeris.\n";
                    break;
                }
                int idx = sNum - 1;
                cout << names[idx] << " pazymiai: ";
                for (int j = 0; j < gradeCounts[idx]; j++) {
                    cout << grades[idx][j] << " ";
                }
                cout << endl;
                break;
            }
            case 4: {
                if (studentCount == 0) {
                    cout << "Nera mokiniu.\n";
                    break;
                }
                int sNum;
                cout << "Mokinio numeris (1-" << studentCount << "): ";
                cin >> sNum;
                if (sNum < 1 || sNum > studentCount) {
                    cout << "Neteisingas numeris.\n";
                    break;
                }
                int idx = sNum - 1;
                if (gradeCounts[idx] == 0) {
                    cout << "Mokinys neturi pazymiu.\n";
                    break;
                }

                int gNum;
                cout << "Pazymio numeris (1-" << gradeCounts[idx] << "): ";
                cin >> gNum;
                if (gNum < 1 || gNum > gradeCounts[idx]) {
                    cout << "Neteisingas numeris.\n";
                    break;
                }
                int gIdx = gNum - 1;

                cout << "Naujas pazymys (1-10): ";
                cin >> grades[idx][gIdx];
                while (grades[idx][gIdx] < 1 || grades[idx][gIdx] > 10) {
                    cout << "Neteisinga, ivaskite nuo 1 iki 10: ";
                    cin >> grades[idx][gIdx];
                }
                cout << "Atnaujinta!\n";
                break;
            }
            case 5:
            case 6:
                cout << "Bus veliau.\n";
                break;
            case 7:
                cout << "Viso gero!\n";
                break;
            default:
                cout << "Neteisingas pasirinkimas.\n";
        }
    } while (choice != 7);

    return 0;
}