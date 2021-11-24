#include <iostream>
#include <map>
#pragma once

class Tool {
protected:
	std::string name;
public:
	Tool() :name("DEFALTE_NAME") {};
	Tool(std::string str) :name(str) {};

	inline void set_name(std::string str) { name = str; }
	inline std::string get_name() { return name; }

	virtual int use(std::string) = 0;
	virtual bool isArtefact() = 0;
};