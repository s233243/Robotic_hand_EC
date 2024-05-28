# Classification of finger movements 

Here is a short explanation of the files contained in this projects.

## arduino_servo
This code contains the arduino code used to receive the data from python (results from the classification) and control the servo motors of the robotic hand.

## catboost_info
This folder only contains information needed for the execution of the CatBoost classifier tested.

## our_input_30
This folder contains all the raw EMG data, features extracted from them and the Principal Components extracted also for different number of PCs used, for a first subject (female).

## our_input_subject2
This folder contains all the raw EMG data, features extracted from them and the Principal Components extracted also for different number of PCs used, for a second subject (male).

## Arduino.py
This code allows the communication of the classification results (stored in a csv) to arduino.

## build.py
This code contains the biggest part of the project : building relavant and correct dataset as input for the classifier. It includes : filtration, envelop detection, segmentation, features extraction and PCA.

## our_ANN1.ipynb
This file contains the coding part for one of the classifier tested, an ANN.

## our_ANN2.ipynb
This file contains the coding part for another classifier tested, an ANN.

## our_RF_and_kNN.ipynb
This file contains the coding part for other classifiers tested, a k-NN, a Random Forest (bagging) and a CatBoost classifier (boosting).
