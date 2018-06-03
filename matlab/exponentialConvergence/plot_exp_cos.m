clear all
close all
clc
%%%% 64-������
% N = 2:10;
% 
% d = [0.2135522670340726
% 0.0042882993300725758
% 3.5367910354189291e-05
% 1.5691275989659914e-07
% 4.3406145344704328e-10
% 8.1956663677829056e-13
% 1.3322676295501878e-15
% 1.1102230246251565e-16
% 0];

%% ���������� �����������
N = 2:18;

d = [20.213552267034072589850301065656363897510930858290745469472485225586823717
0.004288299330072632437184042461422233109404202850800420551159794030487238
3.5367910354361835174971264324956947742360623888649600664759142809945e-05
1.56912759806098256364483714386230598720988413288277453116206485585e-07
4.34061501374646103972216576738893626327877473736683995881574119e-10
8.19648085382654250383407682201231427664252929445875951207757e-13
1.123383747845575106048549268997546938577348213276942008298e-15
1.168164038120228599673306059754761737015574831154496944e-18
9.53059063739288129319431755012218144532472013696207e-22
6.26301003533926834666889149968271022814957028059e-25
3.38586901751833852299813286176691702693393582e-28
1.5322276342029180641586572241184374612949e-31
5.8891390693338043088195988906521770094e-35
1.9463082569042697148292222606158495e-38
5.589928730806942282112796259335e-42
1.40810525618928130227333854e-45
3.13460409864040625629005e-49
];

title('exp(cos(x))');
xlabel('N'); ylabel('lg\delta');
grid on, hold on
plot(N, log10(d), 'k*-')