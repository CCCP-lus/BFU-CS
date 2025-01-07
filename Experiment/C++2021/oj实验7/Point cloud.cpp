#include<bits/stdc++.h>
using namespace std;

void processPoints()
{
	fstream fin;
	fin.open("points.csv");
	fstream fout;
	fout.open("points_offset.csv");
	
	int i = 0;//行数 
	double avex = 0, avey = 0, avez = 0;//均值 
	if(fin.is_open())
	{
		string point;
		while(fin >> point)
		{
			if(i == 0)//第一行 
				fout << point << endl;
			else//点 
			{
				vector<string> vec;
				stringstream isss(point);
				string sim;
				while(getline(isss, sim, ','))
					vec.push_back(sim);
				//xyz 
				double b = atof(vec[0].c_str());
				avex += b;
				double c = atof(vec[1].c_str());
				avey += c;
				double d = atof(vec[2].c_str());
				avez += d;
				//字符串转double 
				if(i > 1)
				{
					avex /= 2;
					avey /= 2;
					avez /= 2;
				}
				fout << fixed << setprecision(3) << b + 100 << "," ;
				fout << fixed << setprecision(3) << c - 50 << "," ;
				fout << fixed << setprecision(3) << d << "," ;
				fout << vec[3] << "," << vec[4] << "," << vec[5] << endl;
			}
			i++;
		}
	}
	fin.close();
	fin.open("points.csv", ios_base::app);
	fin << fixed << setprecision(3) << avex / i << "," ;
	fin << fixed << setprecision(3) << avey / i << "," ;
	fin << fixed << setprecision(3) << avez / i << std::endl;
	fin.close();
	fout.close();
}

int main() {
    std::cout << "Point cloud in processing..." << endl;
    processPoints();
    return 0;
}
 
