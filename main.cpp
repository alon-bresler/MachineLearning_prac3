#include <iostream>
#include <cstdlib>

using namespace std;

//PERCEPTRON RULE//
//weight(new) = weight(old) + n(t)x
//linear activation function
float perceptronLearningRule(float w, float n, int t, int x)
{
    return w + (n*t*x);
}

int linearPerceptron(float w_i, float weight[], int x[])
{
    if (w_i + weight[0]*x[0] + weight[1]*x[1] + weight[2]*x[2] + weight[3]*x[3] > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int trainingData[4][5] = {{1, -1, 1, -1, 1},{1, 1, 1, 1, 1},{1, 1, 1, -1, -1},{1, -1, -1, 1, -1}};
    int perceptrons[4];

    float threshold = -0.5f;
    float learningRate = 0.1f;

    //random initial weights for inputs//
    float weight[4] = {rand()/float(RAND_MAX), rand()/float(RAND_MAX), rand()/float(RAND_MAX), rand()/float(RAND_MAX)};

    int error = 4;

    while (error =! 0)
    {
        int error = 4;

        //adjust weights//
        for (int k = 0; k < 4; k++)
        {
            for (int i = 0; i < 4; i++)
            {
                weight[i] = perceptronLearningRule(weight[i], learningRate, trainingData[i][4], trainingData[k][i]);
            }

            //get linear Perception//
            perceptrons[k] = linearPerceptron(threshold, weight, trainingData[k]);

        }

        //error checking//
        for (int i = 0; i < 4; i++)
        {
            if (perceptrons[i] == trainingData[i][4])
                error--;
        }

        cout << endl;
        cout << "weight 1: " << weight[0] << endl;
        cout << "weight 2: " << weight[1] << endl;
        cout << "weight 3: " << weight[2] << endl;
        cout << "weight 4: " << weight[3] << endl;
        cout << endl;

     }

    cout << "Done" << endl;

    return 0;
}

