/**
 * ####################################################
 * #######  Chemical Periodic Table Lookup App ########
 * ########### Software Version 1.0 Stable ############
 * ############# Software written in C ################
 * ####################################################
 */
#include <stdio.h>
#include <string.h>
// Platform-specific includes
#ifdef _WIN32
#include <windows.h> // For Sleep() on Windows
#else
#include <unistd.h> // For usleep() on Linux/Unix
#include <time.h>   // For nanosleep() on Linux/Unix
#endif

// Function for cross-platform sleep
void cross_platform_sleep(int milliseconds)
{
#ifdef _WIN32
    Sleep(milliseconds); // Sleep for given milliseconds (Windows)
#else
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;               // Seconds
    ts.tv_nsec = (milliseconds % 1000) * 1000000L; // Nanoseconds
    nanosleep(&ts, NULL);                          // High-precision sleep (Linux/Unix)
#endif
}

// Design the element data structure
struct Element
{
    int atomicNumber;
    char atomicSymbol[50];
    char atomName[20];
    double atomicMass;
    char electronic_configuration[50];
};

// Store all elements data
struct Element elements[118] = {
    {1, "H", "Hydrogen", 1.008, "1s1"},
    {2, "He", "Helium", 4.0026, "1s2"},
    {3, "Li", "Lithium", 6.94, "1s2 2s1"},
    {4, "Be", "Beryllium", 9.0122, "1s2 2s2"},
    {5, "B", "Boron", 10.81, "1s2 2s2 2p1"},
    {6, "C", "Carbon", 12.011, "1s2 2s2 2p2"},
    {7, "N", "Nitrogen", 14.007, "1s2 2s2 2p3"},
    {8, "O", "Oxygen", 15.999, "1s2 2s2 2p4"},
    {9, "F", "Fluorine", 18.998, "1s2 2s2 2p5"},
    {10, "Ne", "Neon", 20.180, "1s2 2s2 2p6"},
    {11, "Na", "Sodium", 22.990, "1s2 2s2 2p6 3s1"},
    {12, "Mg", "Magnesium", 24.305, "1s2 2s2 2p6 3s2"},
    {13, "Al", "Aluminium", 26.982, "1s2 2s2 2p6 3s2 3p1"},
    {14, "Si", "Silicon", 28.085, "1s2 2s2 2p6 3s2 3p2"},
    {15, "P", "Phosphorus", 30.974, "1s2 2s2 2p6 3s2 3p3"},
    {16, "S", "Sulfur", 32.06, "1s2 2s2 2p6 3s2 3p4"},
    {17, "Cl", "Chlorine", 35.45, "1s2 2s2 2p6 3s2 3p5"},
    {18, "Ar", "Argon", 39.948, "1s2 2s2 2p6 3s2 3p6"},
    {19, "K", "Potassium", 39.098, "1s2 2s2 2p6 3s2 3p6 4s1"},
    {20, "Ca", "Calcium", 40.078, "1s2 2s2 2p6 3s2 3p6 4s2"},
    {21, "Sc", "Scandium", 44.955, "[Ar] 3d1 4s2"},
    {22, "Ti", "Titanium", 47.867, "[Ar] 3d2 4s2"},
    {23, "V", "Vanadium", 50.942, "[Ar] 3d3 4s2"},
    {24, "Cr", "Chromium", 51.996, "[Ar] 3d5 4s1"},
    {25, "Mn", "Manganese", 54.938, "[Ar] 3d5 4s2"},
    {26, "Fe", "Iron", 55.845, "[Ar] 3d6 4s2"},
    {27, "Co", "Cobalt", 58.933, "[Ar] 3d7 4s2"},
    {28, "Ni", "Nickel", 58.693, "[Ar] 3d8 4s2"},
    {29, "Cu", "Copper", 63.546, "[Ar] 3d10 4s1"},
    {30, "Zn", "Zinc", 65.38, "[Ar] 3d10 4s2"},
    {31, "Ga", "Gallium", 69.723, "[Ar] 3d10 4s2 4p1"},
    {32, "Ge", "Germanium", 72.63, "[Ar] 3d10 4s2 4p2"},
    {33, "As", "Arsenic", 74.922, "[Ar] 3d10 4s2 4p3"},
    {34, "Se", "Selenium", 78.96, "[Ar] 3d10 4s2 4p4"},
    {35, "Br", "Bromine", 79.904, "[Ar] 3d10 4s2 4p5"},
    {36, "Kr", "Krypton", 83.798, "[Ar] 3d10 4s2 4p6"},
    {37, "Rb", "Rubidium", 85.468, "[Kr] 5s1"},
    {38, "Sr", "Strontium", 87.62, "[Kr] 5s2"},
    {39, "Y", "Yttrium", 88.906, "[Kr] 4d1 5s2"},
    {40, "Zr", "Zirconium", 91.224, "[Kr] 4d2 5s2"},
    {41, "Nb", "Niobium", 92.906, "[Kr] 4d4 5s1"},
    {42, "Mo", "Molybdenum", 95.95, "[Kr] 4d5 5s1"},
    {43, "Tc", "Technetium", 98, "[Kr] 4d5 5s2"},
    {44, "Ru", "Ruthenium", 101.07, "[Kr] 4d7 5s1"},
    {45, "Rh", "Rhodium", 102.91, "[Kr] 4d8 5s1"},
    {46, "Pd", "Palladium", 106.42, "[Kr] 4d10"},
    {47, "Ag", "Silver", 107.87, "[Kr] 4d10 5s1"},
    {48, "Cd", "Cadmium", 112.41, "[Kr] 4d10 5s2"},
    {49, "In", "Indium", 114.82, "[Kr] 4d10 5s2 5p1"},
    {50, "Sn", "Tin", 118.71, "[Kr] 4d10 5s2 5p2"},
    {51, "Sb", "Antimony", 121.76, "[Kr] 4d10 5s2 5p3"},
    {52, "Te", "Tellurium", 127.6, "[Kr] 4d10 5s2 5p4"},
    {53, "I", "Iodine", 126.9, "[Kr] 4d10 5s2 5p5"},
    {54, "Xe", "Xenon", 131.29, "[Kr] 4d10 5s2 5p6"},
    {55, "Cs", "Cesium", 132.91, "[Xe] 6s1"},
    {56, "Ba", "Barium", 137.33, "[Xe] 6s2"},
    {57, "La", "Lanthanum", 138.91, "[Xe] 5d1 6s2"},
    {58, "Ce", "Cerium", 140.12, "[Xe] 4f1 5d1 6s2"},
    {59, "Pr", "Praseodymium", 140.91, "[Xe] 4f3 6s2"},
    {60, "Nd", "Neodymium", 144.24, "[Xe] 4f4 6s2"},
    {61, "Pm", "Promethium", 145, "[Xe] 4f5 6s2"},
    {62, "Sm", "Samarium", 150.36, "[Xe] 4f6 6s2"},
    {63, "Eu", "Europium", 151.96, "[Xe] 4f7 6s2"},
    {64, "Gd", "Gadolinium", 157.25, "[Xe] 4f7 5d1 6s2"},
    {65, "Tb", "Terbium", 158.93, "[Xe] 4f9 6s2"},
    {66, "Dy", "Dysprosium", 162.5, "[Xe] 4f10 6s2"},
    {67, "Ho", "Holmium", 164.93, "[Xe] 4f11 6s2"},
    {68, "Er", "Erbium", 167.26, "[Xe] 4f12 6s2"},
    {69, "Tm", "Thulium", 168.93, "[Xe] 4f13 6s2"},
    {70, "Yb", "Ytterbium", 173.04, "[Xe] 4f14 6s2"},
    {71, "Lu", "Lutetium", 174.97, "[Xe] 4f14 5d1 6s2"},
    {72, "Hf", "Hafnium", 178.49, "[Xe] 4f14 5d2 6s2"},
    {73, "Ta", "Tantalum", 180.95, "[Xe] 4f14 5d3 6s2"},
    {74, "W", "Tungsten", 183.84, "[Xe] 4f14 5d4 6s2"},
    {75, "Re", "Rhenium", 186.21, "[Xe] 4f14 5d5 6s2"},
    {76, "Os", "Osmium", 190.23, "[Xe] 4f14 5d6 6s2"},
    {77, "Ir", "Iridium", 192.22, "[Xe] 4f14 5d7 6s2"},
    {78, "Pt", "Platinum", 195.08, "[Xe] 4f14 5d9 6s1"},
    {79, "Au", "Gold", 196.97, "[Xe] 4f14 5d10 6s1"},
    {80, "Hg", "Mercury", 200.59, "[Xe] 4f14 5d10 6s2"},
    {81, "Tl", "Thallium", 204.38, "[Xe] 4f14 5d10 6s2 6p1"},
    {82, "Pb", "Lead", 207.2, "[Xe] 4f14 5d10 6s2 6p2"},
    {83, "Bi", "Bismuth", 208.98, "[Xe] 4f14 5d10 6s2 6p3"},
    {84, "Po", "Polonium", 209, "[Xe] 4f14 5d10 6s2 6p4"},
    {85, "At", "Astatine", 210, "[Xe] 4f14 5d10 6s2 6p5"},
    {86, "Rn", "Radon", 222, "[Xe] 4f14 5d10 6s2 6p6"},
    {87, "Fr", "Francium", 223, "[Rn] 7s1"},
    {88, "Ra", "Radium", 226, "[Rn] 7s2"},
    {89, "Ac", "Actinium", 227, "[Rn] 6d1 7s2"},
    {90, "Th", "Thorium", 232.04, "[Rn] 6d2 7s2"},
    {91, "Pa", "Protactinium", 231.04, "[Rn] 5f2 6d1 7s2"},
    {92, "U", "Uranium", 238.03, "[Rn] 5f3 6d1 7s2"},
    {93, "Np", "Neptunium", 237, "[Rn] 5f4 6d1 7s2"},
    {94, "Pu", "Plutonium", 244, "[Rn] 5f6 7s2"},
    {95, "Am", "Americium", 243, "[Rn] 5f7 7s2"},
    {96, "Cm", "Curium", 247, "[Rn] 5f7 6d1 7s2"},
    {97, "Bk", "Berkelium", 247, "[Rn] 5f9 7s2"},
    {98, "Cf", "Californium", 251, "[Rn] 5f10 7s2"},
    {99, "Es", "Einsteinium", 252, "[Rn] 5f11 7s2"},
    {100, "Fm", "Fermium", 257, "[Rn] 5f12 7s2"},
    {101, "Md", "Mendelevium", 258, "[Rn] 5f13 7s2"},
    {102, "No", "Nobelium", 259, "[Rn] 5f14 7s2"},
    {103, "Lr", "Lawrencium", 262, "[Rn] 5f14 7s2 7p1"},
    {104, "Rf", "Rutherfordium", 267, "[Rn] 5f14 6d2 7s2"},
    {105, "Db", "Dubnium", 270, "[Rn] 5f14 6d3 7s2"},
    {106, "Sg", "Seaborgium", 271, "[Rn] 5f14 6d4 7s2"},
    {107, "Bh", "Bohrium", 270, "[Rn] 5f14 6d5 7s2"},
    {108, "Hs", "Hassium", 277, "[Rn] 5f14 6d6 7s2"},
    {109, "Mt", "Meitnerium", 278, "[Rn] 5f14 6d7 7s2"},
    {110, "Ds", "Darmstadtium", 281, "[Rn] 5f14 6d9 7s1"},
    {111, "Rg", "Roentgenium", 282, "[Rn] 5f14 6d10 7s1"},
    {112, "Cn", "Copernicium", 285, "[Rn] 5f14 6d10 7s2"},
    {113, "Nh", "Nihonium", 286, "[Rn] 5f14 6d10 7s2 7p1"},
    {114, "Fl", "Flerovium", 289, "[Rn] 5f14 6d10 7s2 7p2"},
    {115, "Mc", "Moscovium", 290, "[Rn] 5f14 6d10 7s2 7p3"},
    {116, "Lv", "Livermorium", 293, "[Rn] 5f14 6d10 7s2 7p4"},
    {117, "Ts", "Tennessine", 294, "[Rn] 5f14 6d10 7s2 7p5"},
    {118, "Og", "Oganesson", 294, "[Rn] 5f14 6d10 7s2 7p6"}};

// Function for display the result in console
void displayAtoms(struct Element element)
{
    printf("\033[1;32mSearching......... \033[0m\n\n");
    // Sleep(3000); // Loading Timer For 3 Seconds
    cross_platform_sleep(3000);
    printf("\n\n\033[1;33m############################################################\033[0m\n");
    printf("\033[1;33m## Atom Name: %s \033[0m\n", element.atomName);
    printf("\033[1;33m## Atomic Symbol: %s \033[0m\n", element.atomicSymbol);
    printf("\033[1;33m## Atomic Number: %d \033[0m\n", element.atomicNumber);
    printf("\033[1;33m## Atomic Number: %lf \033[0m\n", element.atomicMass);
    printf("\033[1;33m## Electronic Configuration: %s \033[0m\n", element.electronic_configuration);
    printf("\033[1;33m############################################################\033[0m\n\n\n\n");
}

// Function for search specific atom by providing atomic number
void displayAtomBySearchingAtomicNumber(int userAtomicNumber, struct Element elements[])
{
    for (int i = 0; i < 118; i++)
    {
        if (elements[i].atomicNumber == userAtomicNumber)
        {
            displayAtoms(elements[i]);
            return;
        }
    }

    printf("\033[1;31mAtomic Number of %d is not found\033[0m\n\n", userAtomicNumber);
}

// Function for search specific atom by providing atomic symbol
void displayAtomBySearchingAtomicSymbol(char userAtomicSymbol[], struct Element elements[])
{

    for (int i = 0; i < 118; i++)
    {
        if (strcmp(elements[i].atomicSymbol, userAtomicSymbol) == 0)
        {
            displayAtoms(elements[i]);
            return;
        }
    }

    printf("\033[1;31mAtomic Symbol of %s is not found\033[0m\n\n", userAtomicSymbol);
}

// Function for display the initial screen including some options
void startApp()
{
    int option;
    int atomicNumber;
    char atomicSymbol[3];
    printf("\033[1;32m####################################################\033[0m\n");
    printf("\033[1;32m#######  Chemical Periodic Table Lookup App ########\033[0m\n");
    printf("\033[1;32m########### Software Version 0.1 Alpha #############\033[0m\n");
    printf("\033[1;32m############# Software written in C ################\033[0m\n");
    printf("\033[1;32m####################################################\033[0m\n\n\n");

    printf("You can find your desire Atom by Atomic symbol or Atomic Number\n");
    printf("Choose your option.........\n");
    printf("1. Search atom by Atomic Number\n");
    printf("2. Search atom by Atomic Symbol\n");
    printf("3. Restart app\n");
    printf("4. Terminate app\n\n");
    printf("\033[1;32mEnter your option: \033[0m\t");

    // getting option from the user
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        printf("Enter Atomic Number: \t");
        scanf("%d", &atomicNumber);
        displayAtomBySearchingAtomicNumber(atomicNumber, elements);
        startApp();
        break;

    case 2:
        printf("Enter Atomic Symbol: \t");
        scanf("%s", &atomicSymbol);
        displayAtomBySearchingAtomicSymbol(atomicSymbol, elements);
        startApp();
        break;
    case 3:
        printf("Restarting app.... \n ");
        startApp();
        break;
    case 4:
        printf("Terminating app.... \n ");
        return;
        break;

    default:
        printf("\033[1;31mInvalid Option, The App is Terminated.... \033[0m\n ");
        return;
        break;
    }
}

// main function
int main()
{
    startApp();
}