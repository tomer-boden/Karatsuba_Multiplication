#include "main.h"
using namespace std;

bool getInputFromUser(int& size, char** firstNum, char** secondNum) {
	cout << "please enter number of digits:" << endl;
	string s;
	cin >> s;
	size = stoi(s);
	if (size == 0)
		return true;
	if (!isNumber(s) || (s[0] == '0' && s.length() > 1))
		return false;
	cout << "please enter two numbers:" << endl;
	initNumbersArr(size, firstNum, secondNum);
	cin >> *firstNum >> *secondNum;
	if (!isNumber(*firstNum) || !isNumber(*secondNum) || strlen(*firstNum) != size || strlen(*secondNum) != size)
		return false;
	return true;
}

void initNumbersArr(int& size, char** firstNum, char** secondNum) {
	*firstNum = new char[size + 1];
	*secondNum = new char[size + 1];
}

bool isNumber(const string& s) {
	if (s.length() == 1 && s[0] == 0)
		return true;
	return !s.empty() && find_if(s.begin(),
		s.end(), [](unsigned char c) { return !isdigit(c); }) == s.end();
}

void CharArrToIntArr(char* arr, int*& res)
{
	int size = strlen(arr);
	int i = 0;
	for (; i < size; i++)
	{
		res[i] = arr[i] - '0';
	}
	res[i] = -1;
}


void printResult(int* res, int resSize) {
	int i = 0, j=0;
	while (i < resSize - 1 && res[i] == 0)
	{
		i++;
		j++;
	}
	if (resSize-1 == j) // means num1 or num2 were '0' 
	{
		cout << 0;
		cout << endl;
		return;
	}
	for (i = j; i < resSize && res[i]!=-1; i++) {
		cout << res[i];
	}
	cout << endl;
}


int main(void)
{
	int size = 0, resSize = 0;
	int *num1 = nullptr, *num2 = nullptr, *res;
	char* firstNum = nullptr, * secondNum = nullptr;
	bool valid = getInputFromUser(size, &firstNum, &secondNum); //responsible to recieve the inputs
	if (size == 0)
		return 0;
	if (!valid) {
		cout << "wrong output" << endl;
		return 0;
	}

	resSize = 2 * size;
	res = new int[resSize];
	num1 = new int[size+1];
	num2 = new int[size+1];
	//convert *char arr to *int arr
	CharArrToIntArr(firstNum, num1); 
	CharArrToIntArr(secondNum, num2);
	
	
	auto start = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	longMultiplicationAlgorithm(size, num1, num2, resSize,res);
	auto end = chrono::high_resolution_clock::now();
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("Measure.txt"); 
	myfile << "Time taken by function longMultiplicationAlgorithm is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;

	cout << "Long multiplication : x * y = ";
	printResult(res, resSize);
	delete[] res;
	
	start = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	karatsubaAlgorithm(size, num1, num2,res);
	end = chrono::high_resolution_clock::now();
	time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	myfile << "Time taken by function karatsubaAlgorithm is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;

	cout << "Karatsuba (recursive): x * y = ";
	printResult(res, resSize);
	delete[] res;
	
	start = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	KaratsubaNoRecursion(size, num1, num2,res);
	end = chrono::high_resolution_clock::now();
	time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	myfile << "Time taken by function karatsubaAlgorithm with no recursion is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
	cout << "Karatsuba (no recursive): x * y = ";
	printResult(res, resSize);
	delete[] res;
	
}

