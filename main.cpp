#include <iostream>
#include <cstdlib>

using namespace std;

//VARIABLES//
int trainingData[4][5] = {{1, -1, 1, -1, 1},{1, 1, 1, 1, 1},{1, 1, 1, -1, -1},{1, -1, -1, 1, -1}};
int perceptrons[4] = {0, 0, 0, 0};
float perceptronsF[4] = {0.0f, 0.0f, 0.0f, 0.0f};
float threshold = 0.0f;
float learningRate = 0.1f;
//random initial weights for inputs//
//float weight[4] = {rand()/float(RAND_MAX), rand()/float(RAND_MAX), rand()/float(RAND_MAX), rand()/float(RAND_MAX)};
float weight[4] = {0.0f, 0.0f, 0.0f, 0.0f};

//Threshold function//
int thresholdFunction(int x[])
{
    if ((weight[0]*x[0]) + (weight[1]*x[1]) + (weight[2]*x[2]) + (weight[3]*x[3]) >  threshold)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

//Activation function//
float activationFunction(int x[])
{
   return (weight[0]*x[0]) + (weight[1]*x[1]) + (weight[2]*x[2]) + (weight[3]*x[3]);   
}

void printData(int k)
{
    cout << " ~Training Data " << k << "~" << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << " Input " << i << " [weight" << i << "] = " << 
        trainingData[k][i] << " [" << weight[i] << "]" << endl;
    }

    cout << "Expected output: " << trainingData[k][4] << endl;
    cout << "Perceptron output: " << perceptrons[k] << endl << endl;
    
}

int main()
{
    int error = 4;
    int iterations = 0;

    while (error != 0)
    {
        error = 4;

        iterations++;
        cout << "\n---> Iteration: " << iterations << " <---\n" << endl;

        for (int k = 0; k < 4; k++)
        {
            //adjust weights//
            for (int i = 0; i < 4; i++)
            {
                weight[i] += learningRate * (trainingData[k][4] - perceptrons[k]) * trainingData[k][i];
            }

            //get linear Perception//
            perceptrons[k] = thresholdFunction(trainingData[k]);
            //perceptrons[k] = activationFunction(trainingData[k]);

            printData(k);

        }

        //error checking//
        for (int i = 0; i < 4; i++)
        {
            if (perceptrons[i] == trainingData[i][4])
                error--;
        }

        

     }

    cout << "\nIterations:" << iterations << "\n" << endl;
    cout << "Done" << endl;

    return 0;
}

