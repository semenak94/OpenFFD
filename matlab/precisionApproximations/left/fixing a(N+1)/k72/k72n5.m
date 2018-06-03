%% � ���� ����� �������� z � I ��������� ����������������, �.� 
% z = (Ik/(k!*y))^(1/k)
%
clc 
clear all 
close all
format long

% ����������� k ������� �����-������
k = 7/2;

N = 5;
% x_star = 2;
x_star = 3;
y_star = log(1+exp(x_star));

a0 = 1; b0 = 1;
a = zeros(1,N+1); b = zeros(1,N);

% ������ ���-���� ����� 
j = 1:2*N;
alpha = 2/(2+pi);
y0 = 0.5*y_star*(2*alpha*j/(2*N)+(1-alpha)*(1 - cos(pi*j/(2*N))));
x0 = log(exp(y0)-1);

Y = [0.01492451619428359
0.02984903238856718
0.04477354858285077
0.05969806477713436
0.07462258097141795
0.08954709716570154
0.10447161335998513
0.11939612955426872
0.13432064574855232
0.14924516194283591
0.16416967813711950
0.18697661064338722
0.20978354314965492
0.23259047565592261
0.25539740816219031
0.27820434066845801
0.30101127317472570
0.32381820568099340
0.34662513818726109
0.36943207069352879
0.39223900319979649
0.41504593570606418
0.44455805201988852
0.47407016833371285
0.50358228464753718
0.53309440096136151
0.56260651727518585
0.59211863358901018
0.62163074990283451
0.65114286621665884
0.68065498253048318
0.71016709884430751
0.73967921515813184
0.77406293266623893
0.80844665017434603
0.84283036768245312
0.87721408519056021
0.91159780269866730
0.94598152020677440
0.98036523771488149
1.01474895522298869
1.04913267273109589
1.08351639023920310
1.11790010774731030
1.15484497756908855
1.19178984739086680
1.22873471721264504
1.26567958703442329
1.30262445685620154
1.33956932667797979
1.37651419649975804
1.41345906632153628
1.45040393614331453
1.48734880596509278
1.52429367578687103
1.56123854560864928
1.59818341543042752
1.63512828525220577
1.67207315507398402
1.70901802489576227
1.74596289471754051
1.78290776453931876
1.81985263436109701
1.85679750418287526
1.89374237400465351
1.93068724382643175
1.96507096133453873
1.99945467884264572
2.03383839635075292
2.06822211385886012
2.10260583136696733
2.13698954887507453
2.17137326638318173
2.20575698389128894
2.24014070139939614
2.27452441890750334
2.30890813641561055
2.33842025272943488
2.36793236904325921
2.39744448535708354
2.42695660167090788
2.45646871798473221
2.48598083429855654
2.51549295061238087
2.54500506692620521
2.57451718324002954
2.60402929955385387
2.63354141586767820
2.65634834837394607
2.67915528088021393
2.70196221338648179
2.72476914589274966
2.74757607839901752
2.77038301090528538
2.79318994341155324
2.81599687591782111
2.83880380842408897
2.86161074093035683
2.88441767343662470
2.89934218963090817
2.91426670582519165
2.92919122201947513
2.94411573821375860
2.95904025440804208
2.97396477060232556
2.98888928679660903
3.00381380299089251
3.01873831918517599
3.03366283537945947
3.04858735157374294
]';

X = log(exp(Y)-1); 

I_base = [2.05935211723697797
5.85772808633146802
12.20836249689505593
22.24670654130337155
37.24367857481750121
58.07357359926814411
84.35427015808470230
113.65929481743313545
141.50500865797448569
162.56644043989513193
]';

z = (I_base./(gamma(k+1)*y0)).^(1/k);

I_add = [0.17478387570482029
0.35195988165914027
0.53155860119203413
0.71361096494126031
0.89814825399710263
1.08520210306174802
1.27480450362410425
1.46698780714992560
1.66178472828719759
1.85922834808659854
2.05935211723697797
2.37042589748492194
2.68795998268188763
3.01207885562594058
3.34290910535659958
3.68057945488425720
4.02522078909854653
4.37696618285314276
4.73595092922427430
5.10231256794019483
5.47619091397895286
5.85772808633146447
6.36303930403016782
6.88173565188393166
7.41414272454260637
7.96059295220233665
8.52142570818848277
9.09698741721627968
9.68763166430943556
10.29371930435668858
10.91561857228572663
11.55370519383399142
12.20836249689505593
12.99250510211195042
13.80030354467601228
14.63240431843570377
15.48946882397723002
16.37217361352753642
17.28121063694167958
18.21728748870921777
19.18112765591311586
20.17347076707539344
21.19507284182236617
22.24670654130339642
23.41104623454793909
24.61197147448556422
25.85050700430607762
27.12770114275227584
28.44462614683459734
29.80237857506960708
31.20207965113524651
32.64487562783553187
34.13193815126952302
35.66446462509976811
37.24367857481752253
38.87083001190296727
40.54719579778049621
42.27408000747080052
44.05281429284380579
45.88475824537727021
47.77129975832946940
49.71385538823527384
51.71387071563754745
53.77282070496869437
55.89221006349853837
58.07357359926812279
60.16076908720854277
62.30428525680470386
64.50543122252463490
66.76553971008469546
69.08596730221388782
71.46809468348851624
73.91332688419831243
76.42309352320907578
78.99884904978522115
81.64207298434058657
84.35427015808477336
86.73836322898708318
89.17537926675198889
91.66631522033350166
94.21218225373067412
96.81400585506433742
99.47282594515219500
102.18969698557759784
104.96568808624181202
107.80188311239680843
110.69938079114936613
113.65929481743316387
115.99018311603633435
118.35954857559076459
120.76792380293989027
123.21584687596460128
125.70386137212605604
128.23251639689075887
130.80236661203653625
133.41397226383901398
136.06789921113835362
138.76471895328674577
141.50500865797468464
143.32202265493106097
145.15806548468538040
147.01330285616865012
148.88790153445566489
150.78202934404342273
152.69585517212107106
154.62954897183021785
156.58328176551464139
158.55722564796224106
160.55155378963590351
162.56644043989533088
]';

I = (I_add./(gamma(k+1)*Y)).^(1/k);

% ������ ������� A � B
B = z(1,:) - ones(1,2*N);
A = zeros(2*N,2*N);
for i = 1:size(A,2)
    for j = 1:size(A,2)
        if (j>=1 && j<=N)
            A(i,j) = (y0(i))^(j);
        elseif (j >= N+1 && j <=2*N-1)
            A(i,j) = -z(i)*y0(i)^(j-N);
        elseif (j == 2*N)
            A(i,j) = -z(i)*y0(i)^N + (gamma(k+2)^(-1/k))*(y0(i)^(N+1));
        end
    end
end
disp(A); 
disp(B');
E = A\B';
disp(E);

for j = 1:length(E)
    if (j>=1 && j<=N)
        a(j) = E(j);
    elseif (j >= N+1 && j <=2*N)
        b(j-N) = E(j);
    end
end
a(N+1) = b(N)*gamma(k+2)^(-1/k);
disp('lg(cond(A)):'); disp(log10(cond(A)));
disp('--------------------------------');
disp('������������ �:'); disp(a);
disp('----------------------------');
disp('������������ b:'); disp(b);
disp('----------------------------');

F_base = zeros(1,2*N);
delta_base = zeros(1,2*N);
for j = 1:2*N
    S1 = 0; S2 = 0; 
    for n = 1:N+1 
        S1 = S1 + a(n).*y0(j).^n;
    end
    for m = 1:N
        S2 = S2 + b(m).*y0(j).^m;
    end
    F_base(j) = (a0 + S1)/(b0 + S2);
    delta_base(j) = F_base(j)/z(j)-1;
end
%---------------------------------------
% ������� ��������������� �����

F = zeros(1,length(Y));
delta_additional = zeros(1,length(Y));
for j = 1:length(Y)
    S1 = 0; S2 = 0; 
    for n = 1:N+1 
        S1 = S1 + a(n).*Y(j).^n;
    end
    for m = 1:N
        S2 = S2 + b(m).*Y(j).^m;
    end
    F(j) = (a0 + S1)/(b0 + S2);
    delta_additional(j) = F(j)/I(j)-1;
end

disp('lg(dc):');disp(log10(max(abs(delta_additional))));

grid on, hold on
xlabel('y'); %ylabel('d*10^1^0');
plot(Y,delta_additional, 'k','linewidth', 2.5);
plot(y0,delta_base, 'k*','linewidth',5)
% axis([0 y_star -1.5*10^(-1) 1.5*10^(-1)])
line([0;y_star],[0; 0],'linewidth', 2, 'color', 'black');
line([0;log(1+exp(x_star))],[0; 0],'linewidth', 2, 'color', 'black');
% line([0;0],[-1.25; 1.35],'linewidth', 3, 'color', 'black');
% title({'�������-������������������ �����';['k = ', num2str(k), ', N = ', num2str(N), ', x_d_i_v = ', num2str(x_div)]})
% plot(log(1+exp(x_div)),2*10^-16,'b*');