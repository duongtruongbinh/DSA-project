#include "Sort.cpp"

void Command1(int &argc, char *argv[])
{
    cout << "Input file: " << argv[3] << endl;
    fstream inputFile(argv[3]);
    fstream outputFile("output.txt");

    string tempString;
    getline(inputFile, tempString);
    int size = stoi(tempString);
    cout << "Input size: " << size << endl;
    cout << "------------------------" << endl;

    long long *a = new long long[size];
    long long *b = new long long[size];
    for (int i = 0; i < size; i++)
    {
        inputFile >> a[i];
        b[i] = a[i];
    }

    tempString = argv[2];
    long long compare = 0;
    double runtime = 0;
    if (tempString == "selection-sort")
    {
        selectionSort(a, size, compare);
        selectionSort(b, size, runtime);
        for (int i = 0; i < size; i++)
            outputFile << a[i] << " ";
    }
    if (tempString == "insertion-sort")
    {
        insertionSort(a, size, runtime);
        insertionSort(b, size, compare);
        for (int i = 0; i < size; i++)
            outputFile << a[i] << " ";
    }
    if (tempString == "bubble-sort")
    {
        bubbleSort(a, size, runtime);
        bubbleSort(b, size, compare);
        for (int i = 0; i < size; i++)
            outputFile << a[i] << " ";
    }
    if (tempString == "heap-sort")
    {
        heapSort(a, size, compare);
        heapSort(b, size, runtime);
        for (int i = 0; i < size; i++)
            outputFile << a[i] << " ";
    }
    if (tempString == "merge-sort")
    {
        mergeSort(a, size, 0, size - 1, runtime);
        mergeSort(b, size, 0, size - 1, compare);
        for (int i = 0; i < size; i++)
            outputFile << a[i] << " ";
    }
    if (tempString == "quick-sort")
    {
        quickSort(a, 0, size - 1, runtime);
        quickSort(b, 0, size - 1, compare);
        for (int i = 0; i < size; i++)
            outputFile << a[i] << " ";
    }
    if (tempString == "radix-sort")
    {
        radixSort(a, size, compare);
        radixSort(b, size, runtime);
        for (int i = 0; i < size; i++)
            outputFile << a[i] << " ";
    }
    if (tempString == "shaker-sort")
    {
        shakerSort(a, size, runtime);
        shakerSort(b, size, compare);
        for (int i = 0; i < size; i++)
            outputFile << a[i] << " ";
    }
    if (tempString == "shell-sort")
    {
        shellSort(a, size, compare);
        shellSort(b, size, runtime);
        for (int i = 0; i < size; i++)
            outputFile << a[i] << " ";
    }
    if (tempString == "counting-sort")
    {
        countingSort(a, size, compare);
        countingSort(b, size, runtime);
        for (int i = 0; i < size; i++)
            outputFile << a[i] << " ";
    }
    if (tempString == "flash-sort")
    {
        flashSort(a, size, compare);
        flashSort(b, size, runtime);
        for (int i = 0; i < size; i++)
            outputFile << a[i] << " ";
    }

    tempString = argv[4];
    if (tempString == "-comp" || tempString == "-both")
        cout << "Comparisons: " << compare << endl;
    if (tempString == "-time" || tempString == "-both")
        cout << "Running time: " << runtime << " ms" << endl;

    delete[] a, b;
    inputFile.close();
    outputFile.close();
}

void Command2(int &argc, char *argv[])
{
    cout << "Input size: " << argv[3] << endl;
    cout << "Input order: " << argv[4] << endl;
    fstream inputFile("input.txt");
    fstream outputFile("output.txt");

    int size = atoi(argv[3]);
    long long *a = new long long[size];
    long long *b = new long long[size];
    string tempString = argv[4];

    if (tempString == "-rand")
        GenerateData(a, size, 0);
    if (tempString == "-nsorted")
        GenerateData(a, size, 3);
    if (tempString == "-sorted")
        GenerateData(a, size, 1);
    if (tempString == "-rev")
        GenerateData(a, size, 2);

    inputFile << size << endl;
    outputFile << size << endl;
    for (int i = 0; i < size; i++)
    {
        inputFile << a[i] << " ";
        b[i] = a[i];
    }

    tempString = argv[2];
    long long compare = 0;
    double runtime = 0;

    if (tempString == "selection-sort")
    {
        selectionSort(a, size, compare);
        selectionSort(b, size, runtime);
        for (int i = 0; i < size; i++)
            outputFile << a[i] << " ";
    }
    if (tempString == "insertion-sort")
    {
        insertionSort(a, size, runtime);
        insertionSort(b, size, compare);
        for (int i = 0; i < size; i++)
            outputFile << a[i] << " ";
    }
    if (tempString == "bubble-sort")
    {
        bubbleSort(a, size, runtime);
        bubbleSort(b, size, compare);
        for (int i = 0; i < size; i++)
            outputFile << a[i] << " ";
    }
    if (tempString == "heap-sort")
    {
        heapSort(a, size, compare);
        heapSort(b, size, runtime);
        for (int i = 0; i < size; i++)
            outputFile << a[i] << " ";
    }
    if (tempString == "merge-sort")
    {
        mergeSort(a, size, 0, size - 1, runtime);
        mergeSort(b, size, 0, size - 1, compare);
        for (int i = 0; i < size; i++)
            outputFile << a[i] << " ";
    }
    if (tempString == "quick-sort")
    {
        quickSort(a, 0, size - 1, runtime);
        quickSort(b, 0, size - 1, compare);
        for (int i = 0; i < size; i++)
            outputFile << a[i] << " ";
    }
    if (tempString == "radix-sort")
    {
        radixSort(a, size, compare);
        radixSort(b, size, runtime);
        for (int i = 0; i < size; i++)
            outputFile << a[i] << " ";
    }
    if (tempString == "shaker-sort")
    {
        shakerSort(a, size, runtime);
        shakerSort(b, size, compare);
        for (int i = 0; i < size; i++)
            outputFile << a[i] << " ";
    }
    if (tempString == "shell-sort")
    {
        shellSort(a, size, compare);
        shellSort(b, size, runtime);
        for (int i = 0; i < size; i++)
            outputFile << a[i] << " ";
    }
    if (tempString == "counting-sort")
    {
        countingSort(a, size, compare);
        countingSort(b, size, runtime);
        for (int i = 0; i < size; i++)
            outputFile << a[i] << " ";
    }
    if (tempString == "flash-sort")
    {
        flashSort(a, size, compare);
        flashSort(b, size, runtime);
        for (int i = 0; i < size; i++)
            outputFile << a[i] << " ";
    }

    cout << "------------------------" << endl;

    tempString = argv[5];
    if (tempString == "-comp" || tempString == "-both")
        cout << "Comparisons: " << compare << endl;
    if (tempString == "-time" || tempString == "-both")
        cout << "Running time: " << runtime << " ms" << endl;
    delete[] a, b;
    inputFile.close();
    outputFile.close();
}

void Command3(int &argc, char *argv[])
{
    int size = atoi(argv[3]);
    cout << "Input size: " << size << endl;
    cout << endl;

    long long *a = new long long[size];
    long long *b = new long long[size];

    long long compare;
    double runtime;
    string tempString;

    string order[] = {"Randomize", "Sorted", "Reversed", "Nearly Sorted"};

    string file[] = {"input_1.txt", "input_2.txt", "input_3.txt", "input_4.txt"};

    for (int i = 0; i < 4; i++)
    {
        fstream inputFile(file[i]);
        GenerateData(a, size, i);
        cout << "Input order: " << order[i] << endl;
        cout << "------------------------" << endl;

        inputFile << size << endl;
        for (int j = 0; j < size; j++)
        {
            b[j] = a[j];
            inputFile << a[j] << " ";
        }
        tempString = argv[2];

        compare = 0;
        runtime = 0;
        if (tempString == "selection-sort")
        {
            selectionSort(a, size, compare);
            selectionSort(b, size, runtime);
        }
        if (tempString == "insertion-sort")
        {
            insertionSort(a, size, runtime);
            insertionSort(b, size, compare);
        }
        if (tempString == "bubble-sort")
        {
            bubbleSort(a, size, runtime);
            bubbleSort(b, size, compare);
        }
        if (tempString == "heap-sort")
        {
            heapSort(a, size, compare);
            heapSort(b, size, runtime);
        }
        if (tempString == "merge-sort")
        {
            mergeSort(a, size, 0, size - 1, runtime);
            mergeSort(b, size, 0, size - 1, compare);
        }
        if (tempString == "quick-sort")
        {
            quickSort(a, 0, size - 1, runtime);
            quickSort(b, 0, size - 1, compare);
        }
        if (tempString == "radix-sort")
        {
            radixSort(a, size, compare);
            radixSort(b, size, runtime);
        }
        if (tempString == "shaker-sort")
        {
            shakerSort(a, size, runtime);
            shakerSort(b, size, compare);
        }
        if (tempString == "shell-sort")
        {
            shellSort(a, size, compare);
            shellSort(b, size, runtime);
        }
        if (tempString == "counting-sort")
        {
            countingSort(a, size, compare);
            countingSort(b, size, runtime);
        }
        if (tempString == "flash-sort")
        {
            flashSort(a, size, compare);
            flashSort(b, size, runtime);
        }
        tempString = argv[4];
        if (tempString == "-comp" || tempString == "-both")
            cout << "Comparisons: " << compare << endl;
        if (tempString == "-time" || tempString == "-both")
            cout << "Running time: " << runtime << " ms" << endl;
        cout << endl;
        inputFile.close();
    }

    delete[] a, b;
}

void Command4(int &argc, char *argv[])
{
}

void Command5(int &argc, char *argv[])
{
}

void AlgorithmMode(int &argc, char *argv[])
{
    cout << "ALGORITHM MODE" << endl;
    cout << "Algorithm: " << argv[2] << endl;
    string tempString = argv[4];
    if (!atoi(argv[3]))
        Command1(argc, argv);
    else
    {
        if (tempString != "-comp" && tempString != "-time" && tempString != "-both")
            Command2(argc, argv);
        else
            Command3(argc, argv);
    }
}

void CompareMode(int &argc, char *argv[])
{
    cout << "COMPARE MODE" << endl;
    if (atoi(argv[4]))
        Command4(argc, argv);
    else
        Command5(argc, argv);
}

void Mode(int &argc, char *argv[])
{
    if (argv[1][1] == 'a')
    {
        AlgorithmMode(argc, argv);
    }
    if (argv[1][1] == 'c')
    {
        CompareMode(argc, argv);
    }
}
int main(int argc, char *argv[])
{
    Mode(argc, argv);

    return 0;
}