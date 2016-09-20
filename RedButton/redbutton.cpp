#include "redbutton.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

//Wicked recursive directory removal function.Thanks _JP!

void removeDirectory(const QString& path)
{
    QFileInfo fileInfo(path);
    if (fileInfo.isDir())
    {
        QDir dir(path);
        QStringList entries = dir.entryList(QDir::AllEntries | QDir::NoDotAndDotDot);
        foreach (QString entry, entries)
        {
            removeDirectory(dir.filePath(entry));
        }
        dir.rmdir(path);
    }
    else
    {
        QFile::remove(path);
    }
}

//Take a wild guess at what this does :D
#ifdef YS_2q53452345235
void RedButton::DeleteFiles()
{
SaveToFile(); //lets save the list just in case the user didn't click the save button
QFile data("list.dat"); //our friendly neighbourhood file handle
//Lets ask the user if he clicked the Delete button on purpose
QMessageBox::StandardButton ret = QMessageBox::warning(this, tr("File Deleting"),
                           tr("All files in the list will be unrecoverably deleted from your harddrive.\n"
                              "Are you sure about this?"),
                           QMessageBox::Ok
                           | QMessageBox::Cancel);
 if(ret==QMessageBox::Ok)
 {
  if (data.open(QFile::ReadWrite))
   {
    //Let there be a progress dialog
    QProgressDialog *pd = new QProgressDialog("Deleting files", "Cancel", 0, 100); 
    pd->setWindowModality(Qt::WindowModal);
    pd->setMinimumDuration(0);
    pd->setAutoReset(0); 
    pd->show();
    int cnt=0; //the current value of the progress bar
    int vtoinc; //value to increase 
    if (list->count()<=100)
     {
      vtoinc=100/list->count(); 
     }
    else 
     {
      vtoinc=list->count()/100;
     }; 
    QTextStream in(&data);
    while(!in.atEnd()) 
     {
      QString line=in.readLine(); 
      removeDirectory(line); //lets do this now
      cnt=cnt+vtoinc;
      pd->setValue(cnt); //lets increase the progress bar
      if (pd->wasCanceled()) break; //if it was cancelled lets break the loop
     } 
    if(100 % list->count() !=0){pd->setValue(100);}; //just in case we couldn't increase it to 100
    pd->hide();
    delete pd; //we don't need it anymore so lets not spoil memory
    data.remove(); //what good is a list of removed files ?
    list->clear(); //lets clear the list of phantom files
   }
   else {
         if(data.exists())
         {
          QMessageBox::warning(NULL, "RedButton", "Unable to read from data file.", "OK");
          //Oops,just in case we don't have permision 
         }
        }
 }
}


void RedButton::DeleteItem()
{
 list-> takeItem(list->currentRow());
}

//Saves our list of files
void RedButton::SaveToFile()
{
 QFile data("list.dat");
 if (data.open( QFile::WriteOnly )) 
 {
  QTextStream texts(&data);
  for(int i=0;i<list->count();i++)
   { 
    QString text = (list -> item(i))->text() + "\n"; 
    texts << text;
   }
   data.close();
 }
 else {
         QMessageBox::warning(NULL, "RedButton", "Unable to write data file.", "OK");
      }
}

/*Lets load the data in the file.We wouldn't want to do the list from scratch everytime
 the program loads, would we ?
*/
void RedButton::ReadFromFile()
{
 QFile data("list.dat");
 if (data.open(QFile::ReadOnly))
  {
   QTextStream in(&data);
   while(!in.atEnd()) 
    {
     QString line=in.readLine(); 
     list->addItem(line);
    }
  }
  else {
        if(data.exists())
        {
         QMessageBox::warning(NULL, "RedButton", "Unable to read from data file.", "OK");
        }
       }
}

//Let us select multiple files and put them in the list
void RedButton::InsertFile()
{
  QStringList filelist = QFileDialog::getOpenFileNames(this, tr("Open File"),"/home",tr("Any File (*.*)"));
  
  QStringList::Iterator it = filelist.begin();
  while(it != filelist.end()) 
  {
     list->addItem(*it);
     ++it;
  }
 
}

//Or maybe a whole directory
void RedButton::InsertDir()
{
 QString dir = QFileDialog::getExistingDirectory(this, tr("Select Directory"),
                                                  "/home",
                                                  QFileDialog::ShowDirsOnly
                                                  | QFileDialog::DontResolveSymlinks);
  list->addItem(dir);
}

#endif


//Lets get artistic :D
void RedButton :: BuildInterface()
{
  setWindowTitle("RedButton"); 
  QLabel *title = new QLabel("<center><font size=7 color=red>RedButton</font></center>");
  list = new QListWidget;
  list->setSelectionMode(QAbstractItemView::ExtendedSelection);
  
  fileSelect = new QPushButton("Select Files");
  dirSelect = new QPushButton("Select Directory");
  deleteB = new QPushButton("Remove");
  saveB = new QPushButton("Save List");
  redB = new QPushButton("DELETE");
  QVBoxLayout *l = new QVBoxLayout;
  l -> addWidget(title);
  l -> addWidget(list);
 
  QVBoxLayout *buttonL = new QVBoxLayout;
  buttonL -> addWidget(deleteB); 
  buttonL -> addWidget(fileSelect);
  buttonL -> addWidget(dirSelect);
  buttonL -> addWidget(saveB);
  buttonL -> addWidget(redB);

  QHBoxLayout *main = new QHBoxLayout;
  main ->addLayout(l);
  main ->addLayout(buttonL);
  setLayout(main); 
  QSize size(600, 400);
  resize(size);
}

//Our friendly neighbourhood constructor
//We don't need to destruct anything since we need the objects while the program is running
RedButton :: RedButton()
{
 BuildInterface();
 //ReadFromFile();
 //connect(fileSelect,SIGNAL(clicked()),this,SLOT(InsertFile())); 
 //connect(dirSelect,SIGNAL(clicked()),this,SLOT(InsertDir())); 
 //connect(deleteB,SIGNAL(clicked()),this,SLOT(DeleteItem()));
 //connect(saveB,SIGNAL(clicked()),this,SLOT(SaveToFile()));
 //connect(redB,SIGNAL(clicked()),this,SLOT(DeleteFiles()));
  
}