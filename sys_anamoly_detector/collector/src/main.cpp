#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main (){
    long user, nice, system_kernel, idle, iowait, irq, softirq;
    string label;
    string folderpath = "/proc/stat";

    ifstream inputFile(folderpath);
    if (inputFile.is_open()){
        string line;
        getline(inputFile, line);
        cout << line << endl;
        istringstream(line) >> label >> user >> nice >> system_kernel >> idle >> iowait >> irq >> softirq;
        cout << "cpu name: " << label << "\nnormal process executing: " << user <<  "\nniced process executing: " <<
        nice << "\nkernel processes: " << system_kernel << "\nidle: " <<  idle << "\niowait: " << iowait <<  "\nservicing interrupts: "
         << irq << "\nservicing softirqs: " << softirq << endl;

        inputFile.close();
    }
    else cout << "error not open" << endl;

}