clc;
clear all;
close all;
%%%%%% Crank Nicolson %%%%
dt_1_norm = 6.82957e-5;
dt_05_norm = 1.75551e-5;
dt_0250_norm = 4.37019e-6;
dt_0125_norm = 1.04249e-6;
dt_00625_norm = 2.08597e-7;

norms = [dt_1_norm, dt_05_norm, dt_0250_norm, dt_0125_norm, dt_00625_norm];
k = 1:length(norms);
fit1 = polyfit(k, log2(norms), 1);

times = [0.1, 0.05, 0.0250, 0.0125, 0.00625];
figure;
hold on
loglog(times, norms, '-d', 'MarkerFaceColor', 'red');
xlabel('\Deltat');
ylabel('L^2 norm');
title('CN-AB of order 2');