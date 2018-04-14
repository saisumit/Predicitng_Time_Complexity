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
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix
import pickle
import seaborn as sns 


label_inverse_mappings = { } 
label_inverse_mappings[3] = 'N^2'
label_inverse_mappings[6] = 'sqrtN'
label_inverse_mappings[0] = 'LogN'
label_inverse_mappings[1] = 'N'
label_inverse_mappings[2] = 'N*sqrt(N)'
label_inverse_mappings[4] = 'N^3'
label_inverse_mappings[5] = 'NlogN'

forward_mappings = { }

forward_mappings['N^2']= 3
forward_mappings['sqrtN']=6
forward_mappings['LogN']=0
forward_mappings['N']=1
forward_mappings['N*sqrt(N)']=2
forward_mappings['N^3']= 4
forward_mappings['NlogN']= 5




def complexity_unitary( n , time_taken, p_time  ):

		if(n==0):
			return "N"	
		# print(n,time_taken,p_time)
		calc_time = [None]*7
		calc_time[0] = math.log(n,2.0)*p_time;
		calc_time[1] = n*math.sqrt(n)*p_time;
		calc_time[2] = n*p_time;
		calc_time[3] = n*math.log(n,2.0)*p_time;
		calc_time[4] = n*n*p_time;
		calc_time[5] = n*n*n*p_time;
		calc_time[6] = math.sqrt(n)*p_time;
		
		maxnum = 1e8
		ind = -1 

		for j in range(0,6):
			if abs(calc_time[j]-time_taken)<maxnum:
				maxnum = abs(calc_time[j]-time_taken);
				ind = j;

		if ind==0:
			return "LogN"
		elif ind==1:
			return "N*sqrt(N)" 
		elif ind==2:
			return "N"
		elif ind==3:
			return "NlogN"
		elif ind==4:
			return "N^2"
		elif ind==5:
			return "N^3"
		elif ind==6:
			return "sqrtN" 





labelencoder = LabelEncoder()
train = pd.read_csv("Complexity_features.csv")
import seaborn as sn
print(train['target_complexity'].unique())
train["processor"]=labelencoder.fit_transform(train["processor"])
train["memory_type"]=labelencoder.fit_transform(train["memory_type"])
train['target_complexity'] = labelencoder.fit_transform(train['target_complexity'])
print( "hey", labelencoder.fit_transform( ['N^2' ,  'sqrtN',  'LogN' ,  'N',  'N*sqrt(N)',  'N^3',  'NlogN'] ))
print(train['target_complexity'].unique())

features = train.loc[:,['N','time_taken','clock_time','ram','clock_cycle','processor','series','cores','avg_clock_cycle','memory_type']].values
target = train.loc[:,'target_complexity'].values


X_train, X_test, y_train, y_test = train_test_split( features, target  , test_size=0.2 , random_state=42)
y_train_brute_pred = [None]*len(X_train)
y_test_brute_pred =  [None]*len(y_test)  

for i in range(0,len(X_train)):
	predicted_brute_complexity = complexity_unitary( X_train[i][0], X_train[i][1] , X_train[i][2] ) 
	# print(predicted_brute_complexity,label_inverse_mappings[y_train[i]])
	y_train_brute_pred[i] = forward_mappings [   predicted_brute_complexity ] 



for i in range(0,len(X_test)):
	predicted_brute_complexity = complexity_unitary( X_test[i][0], X_test[i][1] , X_test[i][2] ) 
	# print(predicted_brute_complexity,label_inverse_mappings[y_train[i]])
	y_test_brute_pred[i] = forward_mappings [ predicted_brute_complexity ] 



clf = XGBClassifier( learning_rate=0.03,n_estimators= 200  ,max_depth= 7 ,min_child_weight=0.7,gamma=0,subsample=0.8,colsample_bytree=1,objective= 'binary:logistic',scale_pos_weight=1,seed=27)
clf=clf.fit(X_train,y_train,eval_metric='mlogloss')


plot_importance(clf)
plt.show()
plt.savefig('myfig')



pred=clf.predict(X_train)
print("training accuracy: "+str(metrics.r2_score(y_train,pred)))
conf_arr_train = confusion_matrix( y_train ,  pred )	

pred = clf.predict(X_test)
print("test_accuracy: "+str(metrics.r2_score(y_test,pred)))
conf_arr_test = confusion_matrix( y_test ,  pred )



print("brute_training accuracy: "+str(metrics.r2_score(y_train,y_train_brute_pred)))

print("brute_test accuracy: "+str(metrics.r2_score(y_test,y_test_brute_pred)))

conf_arr_brute_test = confusion_matrix( y_test,y_test_brute_pred )
conf_arr_brute_train = confusion_matrix(y_train,y_train_brute_pred )


# save model to file
pickle.dump( clf, open("sai_model.pickle.dat", "wb"))

# # some time later...

# # load model from file
# loaded_model = pickle.load(open("pima.pickle.dat", "rb"))
# # make predictions for test data
# y_pred = loaded_model.predict(X_test)
# predictions = [round(value) for value in y_pred]
# # evaluate predictions
# accuracy = accuracy_score(y_test, predictions)
# print("Accuracy: %.2f%%" % (accuracy * 100.0))

def print_confusion_matrix(confusion_matrix, class_names, figsize = (10,7), fontsize=14):
	"""Prints a confusion matrix, as returned by sklearn.metrics.confusion_matrix, as a heatmap.
	
	Arguments
	---------
	confusion_matrix: numpy.ndarray
		The numpy.ndarray object returned from a call to sklearn.metrics.confusion_matrix. 
		Similarly constructed ndarrays can also be used.
	class_names: list
		An ordered list of class names, in the order they index the given confusion matrix.
	figsize: tuple
		A 2-long tuple, the first value determining the horizontal size of the ouputted figure,
		the second determining the vertical size. Defaults to (10,7).
	fontsize: int
		Font size for axes labels. Defaults to 14.
		
	Returns
	-------
	matplotlib.figure.Figure
		The resulting confusion matrix figure
	"""
	df_cm = pd.DataFrame(
		confusion_matrix, index=class_names, columns=class_names, 
	)
	fig = plt.figure(figsize=figsize)
	try:
		heatmap = sns.heatmap(df_cm, annot=True, fmt="d")
	except ValueError:
		raise ValueError("Confusion matrix values must be integers.")
	heatmap.yaxis.set_ticklabels(heatmap.yaxis.get_ticklabels(), rotation=0, ha='right', fontsize=fontsize)
	heatmap.xaxis.set_ticklabels(heatmap.xaxis.get_ticklabels(), rotation=45, ha='right', fontsize=fontsize)
	plt.ylabel('True label')
	plt.xlabel('Predicted label')
	return fig


labels = ['LogN' , 'N', 'N*sqrt(N)', 'N^2' , 'N^3', 'NlogN', 'sqrtN' ]

print_confusion_matrix(conf_arr_train,labels)

print_confusion_matrix(conf_arr_test,labels)

print_confusion_matrix(conf_arr_brute_train,labels)

print_confusion_matrix(conf_arr_brute_test,labels)

plt.show()



