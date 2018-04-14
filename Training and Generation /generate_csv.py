import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import xgboost as xgb
import math
import os 
import re
from xgboost import XGBClassifier,XGBRegressor
from sklearn import cross_validation, metrics
from sklearn.ensemble import RandomForestClassifier
from sklearn.ensemble import GradientBoostingClassifier
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.preprocessing import LabelEncoder
from sklearn.preprocessing import LabelEncoder,OneHotEncoder
from sklearn.preprocessing import MultiLabelBinarizer
from sklearn.linear_model import ARDRegression
from xgboost import plot_importance
from sklearn.model_selection import KFold 

TRAINING_FILE_LIST = '../../Complexity_Data/Output_Data/'
Combined_data = [ ] 

def out_to_csv():
	count = 0 
	SUBJECT_LIST = [os.path.splitext(subject)[0] for subject in os.listdir(TRAINING_FILE_LIST)]
	for subject in SUBJECT_LIST:    
		print(subject)
		Complexity = subject  
		OUTPUT_FILE_LIST = [os.path.splitext(subject)[0] for subject in os.listdir(TRAINING_FILE_LIST+subject+'/')]
		for output in OUTPUT_FILE_LIST:
			code_name = output.split('_')
			coder_name = code_name[len(code_name)-1] 
			print("coder_name",coder_name)
			PATH = TRAINING_FILE_LIST + Complexity + '/' + output + ".out" 
			print(PATH)
			with open ( PATH ,"r") as feature: 
				data = feature.read() 
				range_array = data.split("\n")
				for idx in range ( 0 , len(range_array)-1 ):
					# print(range_array[idx]) 
					N,time_taken,clock_time = range_array[idx].split(",")
					
					ram = -1 
					clock_cycle = -1 
					processor = -1 
					series = -1 
					cores = -1 
					avg_clock_cycle = -1 
					memory_type = -1

					if( coder_name == 'sumit'):
						ram,clock_cycle,processor,series,cores,avg_clock_cycle,memory_type = 8,2.5,"i5",7200,4,2.71,"SSD"

					if( coder_name == 'tarun'):
						ram,clock_cycle,processor,series,cores,avg_clock_cycle,memory_type = 4,2.5,"i5",7200,4,2.71,"HDD"

					if( coder_name == 'vipul'):
						ram,clock_cycle,processor,series,cores,avg_clock_cycle,memory_type = 8,2.8,"i7",7700,4,2.81,"HDD"

					target_complexity = Complexity
					if(Complexity == "sqrtN"):
						count = count + 1 
					Combined_data.append ( [ N,time_taken,clock_time,ram,clock_cycle,processor,series,cores,avg_clock_cycle,memory_type,target_complexity ] ) 


	# print(Combined_data)				
 	features = pd.DataFrame( Combined_data, columns= ['N','time_taken','clock_time','ram','clock_cycle','processor','series','cores','avg_clock_cycle','memory_type','target_complexity'] )
 	features.to_csv('Complexity_features.csv',index=False,header=True)
 	print(features)
 	print(count)

out_to_csv()

