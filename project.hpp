#ifndef PROJECT_HPP
#define PROJECT_HPP

#include <QString>
#include <cstdint>
#include "task.hpp"
#include <deque>


class Project{

private:
    QString projectTitle;
    std::deque<Task*> projectTasks;
    QString savePath = "";
    bool modified = 0;

public:
    Project();

    void setTitle(QString newTitle);
    QString getTitle();
    void setSavePath(QString newSavePath);
    QString getSavePath();
    void setModified(bool isModified);
    bool getModified();

    bool loadProject();
    //Debug for new feature
    //bool loadProjectFromFile(QString openFilePath);
    void saveProject(QString currentSavePath = "");

    void addTaskAsChildren(Task *newTask);
    void addTaskAsMaster(Task *newTask);
    std::deque<Task *> getProjectTasks();
    Task* searchById(qint32 Id);
};

#endif // PROJECT_HPP
