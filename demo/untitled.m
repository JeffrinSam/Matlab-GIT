data=readtable('C:\Users\jeffr\Documents\MATLAB\Data Preprocessing\Data_5.csv');
% complete_data=rmmissing(data);
% complete_data=rmmissing(data,2);
% data=complete_data;
% M_Age=mean(data.Age,'omitnan');
% U_age=fillmissing(data.Age,"constant",M_Age);
% data.Age=U_age;
% res_missing=rmmissing(data,'MinNumMissing',3);
% res_missing=rmmissing(data,2,'MinNumMissing',3);
% data.Opinion=categorical(data.Opinion);
% Freq_opinion=mode(data.Opinion);
% Opinion=fillmissing(data.Opinion,'constant',cellstr(Freq_opinion));
% data.Opinion=Opinion;
% stand_age=(data.Age-mean(data.Age))/std(data.Age);
% data.Age=stand_age;
% normalize_age=(data.Age-min(data.Age))/(max(data.Age)-min(data.Age));
% data.Age=normalize_age;
% outliers=isoutlier(data.Age)
% data=data(~outliers,:)
% age=filloutliers(data.Age,'clip','mean');
% data.Age=age;