//
// MainWindow.cpp for Plazza in /home/gastal_r/rendu/Plazza/gui/src/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Mon Apr 24 15:18:54 2017 gastal_r
// Last update Tue Apr 25 15:20:51 2017 sellet_f
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
    QListWidgetItem	*listItem = new QListWidgetItem(listWidget);
    listItem->setIcon(QIcon("res/RedButton.png"));
    listItem->setText("Item " + QString::number(i));
    listWidget->addItem(listItem);
  }
}
