#include "mainwindow.h" //Use all functions and definitions in the mainwindow header
#include <QApplication> //Tell the compiler to include the QApplication header file
int main(int argc, char *argv[]) //Function to be executed on program run (will create the window)
{
    QApplication a(argc, argv); //Create the application object
    MainWindow w; //Creates the object for the main window (this will also call the main window constructor)
    w.show(); //Display the window

    return a.exec(); //Begin the execution loop (run the program)
}
