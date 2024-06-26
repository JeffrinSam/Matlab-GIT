clear all

%% --------------- Importing the dataset -------------------------
% ---------------------------- Code ---------------------------
data = readtable('C:\Users\jeffr\Documents\MATLAB\K-Nearest Neighbor\Social_Network_Ads.csv');



%________________________________________________________________
%________________________________________________________________

%%---------------Data Preprocessing -----------------------------


%% -------------- Feature Scalling -------------------------------

% -------------- Method 1: Standardization ----------------------
% ---------------------------- Code -----------------------------

stand_age = (data.Age - mean(data.Age))/std(data.Age);
data.Age = stand_age; 

stand_estimted_salary = (data.EstimatedSalary - mean(data.EstimatedSalary))/std(data.EstimatedSalary);
data.EstimatedSalary = stand_estimted_salary; 

 
%________________________________________________________________
%________________________________________________________________

%%%%---------------Classifying Data  -----------------------------
%% -------------- Building Classifier ----------------------------
% ---------------------------- Code ---------------------------


classification_model = fitcknn(data,'Purchased~Age+EstimatedSalary');

classification_model_1 = fitcknn(data,'Purchased~Age+EstimatedSalary','Distance','cityblock');
%classification_model_1 = fitcknn(data,'Purchased~Age+EstimatedSalary','Distance','hamming');
%classification_model_1 = fitcknn(data,'Purchased~Age+EstimatedSalary','Distance','chebychev');
%classification_model_1 = fitcknn(data,'Purchased~Age+EstimatedSalary','Distance','correlation');
%classification_model_1 = fitcknn(data,'Purchased~Age+EstimatedSalary','Distance','jaccard');
%classification_model_1 = fitcknn(data,'Purchased~Age+EstimatedSalary','Distance','euclidean');
%classification_model_1 = fitcknn(data,'Purchased~Age+EstimatedSalary','Distance','seuclidean');
%classification_model_1 = fitcknn(data,'Purchased~Age+EstimatedSalary','NumNeighbors',5);
%classification_model_1 = fitcknn(data,'Purchased~Age+EstimatedSalary','BreakTies','smallest');
%classification_model_1 = fitcknn(data,'Purchased~Age+EstimatedSalary','BreakTies','nearest');
%classification_model_1 = fitcknn(data,'Purchased~Age+EstimatedSalary','BreakTies','random');




%% -------------- Test and Train sets ----------------------------
% ---------------------------- Code ---------------------------

cv = cvpartition(classification_model.NumObservations, 'HoldOut', 0.2);
cross_validated_model = crossval(classification_model,'cvpartition',cv); 

cross_validated_model_1 = crossval(classification_model_1,'cvpartition',cv); 


%% -------------- Making Predictions for Test sets ---------------
% ---------------------------- Code ---------------------------

Predictions = predict(cross_validated_model.Trained{1},data(test(cv),1:end-1));

Predictions_1 = predict(cross_validated_model_1.Trained{1},data(test(cv),1:end-1));



%% -------------- Analyzing the predictions ---------------------
% ---------------------------- Code ---------------------------

Results = confusionmat(cross_validated_model.Y(test(cv)),Predictions);

Results_1 = confusionmat(cross_validated_model_1.Y(test(cv)),Predictions_1);


% %% -------------- Visualizing training set results --------------
% % ---------------------------- Code ---------------------------
 
labels = unique(data.Purchased);
classifier_name = 'K-Nearest Neigbor (Default options)';
 
Age_range = min(data.Age(training(cv)))-1:0.01:max(data.Age(training(cv)))+1;
Estimated_salary_range = min(data.EstimatedSalary(training(cv)))-1:0.01:max(data.EstimatedSalary(training(cv)))+1;

[xx1, xx2] = meshgrid(Age_range,Estimated_salary_range);
XGrid = [xx1(:) xx2(:)];
 
predictions_meshgrid = predict(cross_validated_model.Trained{1},XGrid);
 
gscatter(xx1(:), xx2(:), predictions_meshgrid,'rgb');
 
hold on
training_data = data(training(cv),:);
Y = ismember(training_data.Purchased,labels{1});
 
scatter(training_data.Age(Y),training_data.EstimatedSalary(Y), 'o' , 'MarkerEdgeColor', 'black', 'MarkerFaceColor', 'red');
scatter(training_data.Age(~Y),training_data.EstimatedSalary(~Y) , 'o' , 'MarkerEdgeColor', 'black', 'MarkerFaceColor', 'green');
 
 
xlabel('Age');
ylabel('Estimated Salary');
 
title(classifier_name);
legend off, axis tight
 
legend(labels,'Location',[0.45,0.01,0.45,0.05],'Orientation','Horizontal');
 
%________________________________________________________________
%________________________________________________________________
 
 
% %% -------------- Visualizing training set results --------------
% % ---------------------------- Code ---------------------------
 
labels = unique(data.Purchased);
classifier_name = 'K-Nearest Neigbor (Modified options)';
 
Age_range = min(data.Age(training(cv)))-1:0.01:max(data.Age(training(cv)))+1;
Estimated_salary_range = min(data.EstimatedSalary(training(cv)))-1:0.01:max(data.EstimatedSalary(training(cv)))+1;

[xx1, xx2] = meshgrid(Age_range,Estimated_salary_range);
XGrid = [xx1(:) xx2(:)];
 
predictions_meshgrid = predict(cross_validated_model_1.Trained{1},XGrid);

figure
gscatter(xx1(:), xx2(:), predictions_meshgrid,'rgb');
 
hold on
training_data = data(training(cv),:);
Y = ismember(training_data.Purchased,labels{1});
 
scatter(training_data.Age(Y),training_data.EstimatedSalary(Y), 'o' , 'MarkerEdgeColor', 'black', 'MarkerFaceColor', 'red');
scatter(training_data.Age(~Y),training_data.EstimatedSalary(~Y) , 'o' , 'MarkerEdgeColor', 'black', 'MarkerFaceColor', 'green');
 
 
xlabel('Age');
ylabel('Estimated Salary');
 
title(classifier_name);
legend off, axis tight
 
legend(labels,'Location',[0.45,0.01,0.45,0.05],'Orientation','Horizontal');
 
%________________________________________________________________
%________________________________________________________________
 
 
%% -------------- Visualizing testing set results ----------------
% ---------------------------- Code ---------------------------
 
% labels = unique(data.Purchased);
% classifier_name = 'K-Nearest Neigbor';
% 
% Age_range = min(data.Age(training(cv)))-1:0.01:max(data.Age(training(cv)))+1;
% Estimated_salary_range = min(data.EstimatedSalary(training(cv)))-1:0.01:max(data.EstimatedSalary(training(cv)))+1;
% [xx1, xx2] = meshgrid(Age_range,Estimated_salary_range);
% XGrid = [xx1(:) xx2(:)];
% 
% predictions_meshgrid = predict(cross_validated_model.Trained{1},XGrid);
% 
% gscatter(xx1(:), xx2(:), predictions_meshgrid,'rgb');
% 
% hold on

% test_data = data(test(cv),:);
% Y = ismember(data.Purchased,labels{1});
%  
% scatter(test_data.Age(Y),test_data.EstimatedSalary(Y), 'o' , 'MarkerEdgeColor', 'black', 'MarkerFaceColor', 'red');
% scatter(test_data.Age(~Y),test_data.EstimatedSalary(~Y) , 'o' , 'MarkerEdgeColor', 'black', 'MarkerFaceColor', 'green');
% 
% 
% xlabel('Age');
% ylabel('Estimated Salary');
% 
% title(classifier_name);
% legend off, axis tight
% 
% legend(labels,'Location',[0.45,0.01,0.45,0.05],'Orientation','Horizontal');
 
%________________________________________________________________
%________________________________________________________________





