// volctrl.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "mediadevice.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

vector<string> splitEx(const string& src, string separate_character)
{
	vector<string> strs;

	int separate_characterLen = separate_character.size();//分割字符串的长度,这样就可以支持如“,,”多字符串的分隔符
	int lastPosition = 0, index = -1;
	while (-1 != (index = src.find(separate_character, lastPosition)))
	{
		strs.push_back(src.substr(lastPosition, index - lastPosition));
		lastPosition = index + separate_characterLen;
	}
	string lastString = src.substr(lastPosition);//截取最后一个分隔符后的内容
	if (!lastString.empty())
		strs.push_back(lastString);//如果最后一个分隔符后还有内容就入队
	return strs;
}


int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		return -1;
	}
	fstream fs("data.bin", ios::out|ios::trunc);
	if (!fs.is_open())
	{
		printf("open file error:%s", "data.bin");
		return -1;
	}

	vector<string> str_vec = splitEx(argv[1], ",");
	float val = 0; 
	if (str_vec[0] == "1")
	{
		GetSystemVolume(val);
		fs << val;
		printf("%d", (int)val);
		return (int)val;
	}
	else if (str_vec[0] == "2")
	{
		unsigned int val = atoi(str_vec[1].c_str());
		SetSystemVolume(val);
		return val;
	}
	else if (str_vec[0] == "3")
	{
		DWORD vol;
		GetMicrophoneValue(vol);
		fs << vol;
		printf("%u", vol);
		return vol;
	}
	else if (str_vec[0] == "4" )
	{
		unsigned int vol = atoi(str_vec[1].c_str());
		SetMicrophoneValue(vol);
		DWORD d;
		GetMicrophoneValue(d);
		printf("%d", d);
		return vol;
	}
	else if (str_vec[0] == "5")
	{
		float min, max, step;

		GetMicroBoostData(min, max, step);
		fs << min << "," << max << "," << step;
		printf("%f,%f,%f", min, max, step);
		return min;
	}
	else if (str_vec[0] == "6")
	{
		bool mute = atoi(str_vec[1].c_str());
		SetSpeakerMute(mute);
		return 0;
	}
	else if (str_vec[0] == "7")
	{
		bool mute = atoi(str_vec[1].c_str());
		SetMicrophoneMute(mute);
		return 0;
	}
	else if (str_vec[0] == "8")
	{
		unsigned int vol = atoi(str_vec[1].c_str());
		SetMicroBoostLevel(vol);
		return vol;
	}
	fs.close();
	return 0;
}

