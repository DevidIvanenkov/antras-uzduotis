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

    auto checkStudents = [&]() {
        if (studentCount == 0) {
            cout << "Sarase nera mokiniu.\n";
            return false;
        }
        return true;
    };

    auto getStudentIdx = [&]() {
        int sNum;
        cout << "Iveskite mokinio numeri (nuo 1 iki " << studentCount << "): ";
        cin >> sNum;
        while (sNum < 1 || sNum > studentCount) {
            cout << "Neteisingas mokinio numeris. Iveskite skaiciu nuo 1 iki " << studentCount << ": ";
            cin >> sNum;
        }
        return sNum - 1;
    };

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
                if (!checkStudents()) break;
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
            case 3: {
                if (!checkStudents()) break;
                int idx = getStudentIdx();
                cout << "Mokinys: " << names[idx] << "\nPazymiai: ";
                if (gradeCounts[idx] == 0) {
                    cout << "nera pazymiu";
                } else {
                    for (int j = 0; j < gradeCounts[idx]; j++) {
                        cout << grades[idx][j] << " ";
                    }
                }
                cout << endl;
                break;
            }
            case 4: {
                if (!checkStudents()) break;
                int idx = getStudentIdx();
                if (gradeCounts[idx] == 0) {
                    cout << "Sis mokinys neturi pazymiu, kuriuos butu galima atnaujinti.\n";
                    break;
                }

                int gNum;
                cout << "Iveskite pazymio numeri (nuo 1 iki " << gradeCounts[idx] << "): ";
                cin >> gNum;
                while (gNum < 1 || gNum > gradeCounts[idx]) {
                    cout << "Neteisingas pazymio numeris. Iveskite skaiciu nuo 1 iki " << gradeCounts[idx] << ": ";
                    cin >> gNum;
                }
                int gIdx = gNum - 1;

                int newGrade;
                cout << "Iveskite nauja pazymi (nuo 1 iki 10): ";
                cin >> newGrade;
                while (newGrade < 1 || newGrade > 10) {
                    cout << "Neteisingas pazymys. Iveskite nauja pazymi nuo 1 iki 10: ";
                    cin >> newGrade;
                }

                grades[idx][gIdx] = newGrade;
                cout << "Pazymys sekmingai atnaujintas!\n";
                break;
            }
            case 5: {
                if (!checkStudents()) break;
                int idx = getStudentIdx();
                if (gradeCounts[idx] == 0) {
                    cout << "Mokinys neturi pazymiu, vidurkio apskaiciuoti neimanoma.\n";
                } else {
                    double sum = 0;
                    for (int j = 0; j < gradeCounts[idx]; j++) {
                        sum += grades[idx][j];
                    }
                    double avg = sum / gradeCounts[idx];
                    cout << fixed << setprecision(2);
                    cout << "Mokinio " << names[idx] << " vidurkis: " << avg << endl;
                }
                break;
            }
            case 6: {
                if (!checkStudents()) break;
                int idx = getStudentIdx();
                for (int i = idx; i < studentCount - 1; i++) {
                    names[i] = names[i + 1];
                    gradeCounts[i] = gradeCounts[i + 1];
                    for (int j = 0; j < MAX_GRADES; j++) {
                        grades[i][j] = grades[i + 1][j];
                    }
                }
                studentCount--;
                cout << "Mokinys sekmingai pasalintas, o sarasas atnaujintas.\n";
                break;
            }
            case 7:
                cout << "Programa baigia darba. Viso gero!\n";
                break;
            default:
                cout << "Neteisingas pasirinkimas. Pasirinkite nuo 1 iki 7.\n";
        }
    } while (choice != 7);

    return 0;
}