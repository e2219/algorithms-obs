#ifndef CD_H
#define CD_H

class Cd{
private:
    char* performers;
    char* label;
    int selections;
    double playtime;
public:
    Cd(const char* s1, const char* s2, int n, double playtimes);
    Cd(const Cd & d);
    Cd();
    virtual ~Cd();
    virtual void Report() const;
    Cd & operator=(const Cd & d);
};

class Classic : public Cd{
private:
    char* work = nullptr;;
public:
    Classic(const Classic & d);
    Classic(const char* s1 = "unknown", const char* s2 = "unknown", int n = 0, double playtimes = 0, const char* w = "nowork");
    ~Classic() override;
    void Report() const;
    Classic & operator=(const Classic & d);
};

#endif