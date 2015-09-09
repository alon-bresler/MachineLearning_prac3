#include <iostream>
#include <cstdlib>

using namespace std;

//VARIABLES//
int trainingData[4][5] = {{1, -1, 1, -1, 1},{1, 1, 1, 1, 1},{1, 1, 1, -1, -1},{1, -1, -1, 1, -1}};
int perceptrons[4] = {0, 0, 0, 0};
float perceptronsF[4] = {0.0f, 0.0f, 0.0f, 0.0f};
float threshold = 0.0f;
float learningRate = 0.1f;
float weight[4] = {0.0f, 0.0f, 0.0f, 0.0f};

//BOOLEANS TO TELL WHICH LEARNING RULE TO USE//
bool useThreshold = true;

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
    if (!useThreshold) {cout << "Perceptron output: " << perceptronsF[k] << endl << endl;}
    if (useThreshold) {cout << "Perceptron output: " << perceptrons[k] << endl << endl;}
    
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
        
        //LINEAR ACTIVATION FUNCTION//
        if (!useThreshold)
        {
            for (int k = 0; k < 4; k++)
            {              
                perceptronsF[k] = activationFunction(trainingData[k]);

                //adjust weights//
                for (int i = 0; i < 4; i++)
                {
                    weight[i] += learningRate * (trainingData[k][4] - perceptronsF[k]) * trainingData[k][i];
                }

                printData(k);

            }

            //error checking//
            for (int i = 0; i < 4; i++)
            {
                //BASICLY ROUNDING OFF
                if (perceptronsF[i] >= 0.999998)
                {
                    perceptronsF[i] = 1;
                }
                if (perceptronsF[i] <= -0.999998)
                {
                    perceptronsF[i] = -1;
                }

                //ERROR CHECKING//
                if (perceptronsF[i] == trainingData[i][4])
                    error--;
            }
        }

        //THRESHOLD LEARNING FUNCTION//
        if (useThreshold)
        {
            for (int k = 0; k < 4; k++)
            {              
                perceptrons[k] = thresholdFunction(trainingData[k]);

                //adjust weights//
                for (int i = 0; i < 4; i++)
                {
                    weight[i] += learningRate * (trainingData[k][4] - perceptrons[k]) * trainingData[k][i];
                }

                printData(k);

            }

            //error checking//
            for (int i = 0; i < 4; i++)
            {
                if (perceptrons[i] == trainingData[i][4])
                    error--;
            }
        }
        

     }

    cout << "\nIterations:" << iterations << "\n" << endl;

    return 0;
}

