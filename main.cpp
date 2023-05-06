#include <iostream>
#include "StudentsDB.h"
#include "ConsoleHelper.h"

using namespace std;

int main() {
    StudentsDB db;
    db.Init();

    PrintStudents(db.ToVector());

    return 0;
}
