#ifndef ACTION_H_
#define ACTION_H_

//need to make sure we dont include to much
#include <string>
#include <iostream>
#include "Customer.h"
#include "Trainer.h"

enum ActionStatus{
    COMPLETED, ERROR
};

//Forward declaration
class Studio;

extern Studio *backup;
class BaseAction{
public:
    BaseAction();
    ActionStatus getStatus() const;
    virtual void act(Studio& studio)=0;
    virtual std::string toString() const=0;
    virtual BaseAction* clone() = 0;
    virtual ~BaseAction();
    void set_status(ActionStatus status);
    void set_error_msg(string errormsg);
protected:
    void complete();
    void error(std::string errorMsg);
    std::string getErrorMsg() const;
private:
    std::string errorMsg;
    ActionStatus status;
};


class OpenTrainer : public BaseAction {
public:
   
    OpenTrainer(int id, std::vector<Customer *> &customersList);
    void act(Studio &studio);
    std::string toString() const;
    virtual OpenTrainer* clone();
    void set_customers_descriptions(string s);
    ~OpenTrainer();
private:
	const int trainerId;
	std::vector<Customer *> customers;
    std::string customers_descriptions;
};

class Order : public BaseAction {
public:
    Order(int id);
    void act(Studio &studio);
    std::string toString() const;
    virtual Order* clone();
    ~Order();
private:
    const int trainerId;
};

class MoveCustomer : public BaseAction {
public:
    MoveCustomer(int src, int dst, int customerId);
    void act(Studio &studio);
    std::string toString() const;
    virtual MoveCustomer* clone();
    ~MoveCustomer();
private:
    const int srcTrainer;
    const int dstTrainer;
    const int id;
};

class Close : public BaseAction {
public:
    Close(int id);
    void act(Studio &studio);
    std::string toString() const;
    virtual Close* clone();
    ~Close();
private:
    const int trainerId;
};


class CloseAll : public BaseAction {
public:
    CloseAll();
    void act(Studio &studio);
    std::string toString() const;
    virtual CloseAll* clone();
    ~CloseAll();
private:
};


class PrintWorkoutOptions : public BaseAction {
public:
    PrintWorkoutOptions();
    void act(Studio &studio);
    std::string toString() const;
    virtual PrintWorkoutOptions* clone();
    ~PrintWorkoutOptions();
private:
};


class PrintTrainerStatus : public BaseAction {
public:
    PrintTrainerStatus(int id);
    void act(Studio &studio);
    std::string toString() const;
    virtual PrintTrainerStatus* clone();
    ~PrintTrainerStatus();
private:
    const int trainerId;
};


class PrintActionsLog : public BaseAction {
public:
    PrintActionsLog();
    void act(Studio &studio);
    std::string toString() const;
    virtual PrintActionsLog* clone();
    ~PrintActionsLog();
private:
};


class BackupStudio : public BaseAction {
public:
    BackupStudio();
    void act(Studio &studio);
    std::string toString() const;
    virtual BackupStudio* clone();
    ~BackupStudio();
private:
};


class RestoreStudio : public BaseAction {
public:
    RestoreStudio();
    void act(Studio &studio);
    std::string toString() const;
    virtual RestoreStudio* clone();
    ~RestoreStudio();
};

#endif