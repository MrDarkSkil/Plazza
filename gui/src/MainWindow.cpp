//
// MainWindow.cpp for Plazza in /home/gastal_r/rendu/Plazza/gui/src/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Mon Apr 24 15:18:54 2017 gastal_r
// Last update Tue Apr 25 12:31:04 2017 gastal_r
//

#include      <QtGui>
#include      "MainWindow.hpp"
#include      <iostream>

MainWindow::MainWindow()
{
  setupUi(this);
  setWindowTitle("Plazza");
  listView();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
  event->accept();
}

void MainWindow::listView()
{
  for(int i = 0; i < 50; i++)
  {
    listWidget->addItem("Item " + QString::number(i));
  }
  listWidget->item(10)->setText("JE SUCE DES ENORMES CHIBRES");
}
