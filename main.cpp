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
            cout << "Neteisinga ivestis. Bandykite dar karta.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                if (studentCount >= MAX_STUDENTS) {
                    cout << "Pasiektas maksimalus mokiniu limitas (100).\n";
                    break;
                }
                cout << "Iveskite mokinio varda: ";
                cin >> names[studentCount];

                int gCount;
                cout << "Kiek pazymiu norite ivesti (iki 10)? ";
                cin >> gCount;

                while (gCount < 1 || gCount > MAX_GRADES) {
                    cout << "Neteisingas pazymiu skaicius. Iveskite nuo 1 iki 10: ";
                    cin >> gCount;
                }

                gradeCounts[studentCount] = gCount;
                cout << "Iveskite " << gCount << " pazymius (skaiciai nuo 1 iki 10):\n";
                for (int i = 0; i < gCount; i++) {
                    int grade;
                    cin >> grade;
                    while (grade < 1 || grade > 10) {
                        cout << "Neteisingas pazymys (" << grade << "). Iveskite pazymi nuo 1 iki 10: ";
                        cin >> grade;
                    }
                    grades[studentCount][i] = grade;
                }
                studentCount++;
                cout << "Mokinys sekmingai pridetas!\n";
                break;
            }
            case 2: {
                if (studentCount == 0) {
                    cout << "Sarase nera mokiniu.\n";
                    break;
                }
                cout << "\n--- VISU MOKINIU PAZYMIAI ---\n";
                for (int i = 0; i < studentCount; i++) {
                    cout << i + 1 << ". " << names[i] << " - Pazymiai: ";
                    if (gradeCounts[i] == 0) {
                        cout << "nera pazymiu";
                    } else {
                        for (int j = 0; j < gradeCounts[i]; j++) {
                            cout << grades[i][j] << " ";
                        }
                    }
                    cout << endl;
                }
                break;
            }
            case 3:
            case 4:
            case 5:
            case 6:
                cout << "Funkcija veliau bus realizuota.\n";
                break;
            case 7:
                cout << "Programa baigia darba. Viso gero!\n";
                break;
            default:
                cout << "Neteisingas pasirinkimas. Pasirinkite nuo 1 iki 7.\n";
        }
    } while (choice != 7);

    return 0;
}