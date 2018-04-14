X = load('iris.data');
X = X(:,1:4);
rot = load('out.txt');
X2(:,1) = X(:,1).*X(:,2);
X2(:,2) = X(:,3).*X(:,4);
%function [PC V signals] = runPCA(X)

[N,P] = size(X);
% subtract off the mean for each dimension
mn = mean(X,1);
X = X - repmat(mn,N,1);
% calculate the covariance matrix
covariance = 1 / (N-1) * (X') * X;
% find the eigenvectors and eigenvalues
[PC, V] = eig(covariance);
% extract diagonal of matrix as vector
V = diag(V);
% sort the variances in decreasing order
[junk, rindices] = sort(-1*V);
V = V(rindices);
PC = PC(:,rindices);
% project the original data set
signals = X * PC(:,1:2);

rotOrg = [ones(50,1)*1; ones(50,1)*2 ;ones(50,1)*3;];

figure();
gscatter(signals(:,1),signals(:,2),rot);
grid;
title('Usando PCA no KNN usando leave-one-out');

figure();
gscatter(signals(:,1),signals(:,2),rotOrg);
grid;
title('Dados originais depois do PCA');
