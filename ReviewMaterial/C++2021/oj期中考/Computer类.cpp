#include<bits/stdc++.h>
using namespace std;

class CPU
{
private:
	std::string cpuType;
	double frequency;
public:
	CPU();
	CPU(std::string cpuType_, double frequency_);
	std::string getcpuType();
	double getfrequency();
	~CPU();
};

class Disk
{
private:
	std::string diskType;
	double mount;
public:
	Disk();
	Disk(std::string diskType_, double mount_);
	std::string getdiskType();
	double getmount();
	~Disk();
};

class Computer
{
private:
	CPU cpu;
	Disk disk;
public:
	Computer(CPU cpu_, Disk disk_);
	void Print();	
	~Computer();
};

CPU::CPU()
{
	
}

CPU::CPU(std::string cpuType_, double frequency_)
{
	this ->cpuType = cpuType_;
	this ->frequency = frequency_;
}

std::string CPU::getcpuType()
{
	return this->cpuType;
}

double CPU::getfrequency()
{
	return this ->frequency;
}

CPU::~CPU()
{
	
}

std::string Disk::getdiskType()
{
	return this ->diskType;	
}

double Disk::getmount()
{
	return this ->mount;
}

Disk::Disk()
{
	
}

Disk::Disk(std::string diskType_, double mount_)
{
	this ->diskType = diskType_;
	this ->mount = mount_;
}

Disk::~Disk()
{
	
}

Computer::Computer(CPU cpu_, Disk disk_)
{
	this ->cpu = cpu_;
	this ->disk = disk_;
}

void Computer::Print()
{
	std::cout << "The computer has a cpu and a disk.\n";
	std::cout << "CPU type: " << cpu.getcpuType() << ", CPU frequency: " << cpu.getfrequency() << " GHz\n";
	std::cout << "disk type: " << disk.getdiskType() << ", disk capacity: " << disk.getmount() << " T";
}

Computer::~Computer()
{
	
}

int main()
{
    string cpuType, diskType;
    double frequency, capacity;
    cin >> cpuType >> frequency >> diskType >> capacity;
    CPU cpu(cpuType, frequency);
    Disk disk(diskType, capacity);
    Computer computer(cpu, disk);

    computer.Print();
    return 0;
}
