#include <iostream>
#include <cstdlib>

using namespace std;

//VARIABLES//
int trainingData[4][5] = {{1, -1, 1, -1, 1},{1, 1, 1, 1, 1},{1, 1, 1, -1, -1},{1, -1, -1, 1, -1}};
int perceptrons[4] = {0, 0, 0, 0};
float threshold = -1.0f;
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
int activationFunction(int x[])
{
    if ((weight[0]*x[0]) + (weight[1]*x[1]) + (weight[2]*x[2]) + (weight[3]*x[3]) >  0.0f)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}



int main()
{
    int error = 4;
    int iterations = 0;

    while (error != 0)
    {
        error = 4;

        iterations++;
        cout << "---> Iteration: " << iterations << " <---\n" << endl;

        for (int k = 0; k < 4; k++)
        {
            //adjust weights//
            for (int i = 0; i < 4; i++)
            {
                weight[i] += learningRate * (trainingData[k][4] - perceptrons[k]) * trainingData[k][i];
            }

            //get linear Perception//
            perceptrons[k] = thresholdFunction(trainingData[k]);

        }

        //error checking//
        for (int i = 0; i < 4; i++)
        {
            if (perceptrons[i] == trainingData[i][4])
                error--;
        }

        cout << endl;
        cout << "p 1: " << perceptrons[0] << endl;
        cout << "p 2: " << perceptrons[1] << endl;
        cout << "p 3: " << perceptrons[2] << endl;
        cout << "p 4: " << perceptrons[3] << endl;
        cout << "error: " << error << endl;
        cout << endl;

     }

    cout << "\nIterations:" << iterations << "\n" << endl;
    cout << "Done" << endl;

    return 0;
}

