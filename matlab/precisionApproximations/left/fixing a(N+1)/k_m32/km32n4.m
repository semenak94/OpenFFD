%% � ���� ����� �������� z � I ��������� ����������������, �.� 
% z = (Ik/(k!*y))^(1/k)
%
clc 
clear all 
close all
format long

% ����������� k ������� �����-������
k = -3/2;

N = 4;
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

Y = [0.01992070521711391
0.03984141043422781
0.05976211565134172
0.07968282086845563
0.09960352608556954
0.11952423130268344
0.13944493651979734
0.15936564173691126
0.17928634695402518
0.19920705217113910
0.21912775738825302
0.25095745333880926
0.28278714928936549
0.31461684523992173
0.34644654119047796
0.37827623714103420
0.41010593309159044
0.44193562904214667
0.47376532499270291
0.50559502094325914
0.53742471689381544
0.56925441284437173
0.61019885569468346
0.65114329854499520
0.69208774139530693
0.73303218424561867
0.77397662709593040
0.81492106994624214
0.85586551279655387
0.89680995564686561
0.93775439849717734
0.97869884134748908
1.01964328419780093
1.06552059252408005
1.11139790085035917
1.15727520917663829
1.20315251750291741
1.24902982582919653
1.29490713415547565
1.34078444248175477
1.38666175080803389
1.43253905913431301
1.47841636746059213
1.52429367578687125
1.57017098411315037
1.61604829243942949
1.66192560076570861
1.70780290909198773
1.75368021741826685
1.79955752574454597
1.84543483407082509
1.89131214239710421
1.93718945072338333
1.98306675904966245
2.02894406737594135
2.06988851022625298
2.11083295307656460
2.15177739592687622
2.19272183877718785
2.23366628162749947
2.27461072447781110
2.31555516732812272
2.35649961017843435
2.39744405302874597
2.43838849587905759
2.47933293872936922
2.51116263467992562
2.54299233063048202
2.57482202658103843
2.60665172253159483
2.63848141848215123
2.67031111443270763
2.70214081038326404
2.73397050633382044
2.76580020228437684
2.79762989823493324
2.82945959418548965
2.84938029940260362
2.86930100461971760
2.88922170983683158
2.90914241505394555
2.92906312027105953
2.94898382548817350
2.96890453070528748
2.98882523592240146
3.00874594113951543
3.02866664635662941
3.04858735157374339
]';

X = log(exp(Y)-1); 

I_base = [-0.51880090759084294
-0.75167482653908124
-0.81491386392686127
-0.69709005132740798
-0.53297545282361658
-0.39816010891127657
-0.31042524423463247
-0.26367194549353357

]';

z = (I_base./(gamma(k+1)*y0)).^(1/k);

I_add = [-nan
-nan
-nan
-nan
-nan
-nan
nan
nan
nan
nan
-0.51880090759084294
-0.53880090759084294
-0.54880090759084294
-0.56880090759084294
-0.58880090759084294
-0.61880090759084294
-0.64730681673439716
-0.67306255103869750
-0.69622864302712839
-0.71695749996259839
-0.73539379273902150
-0.75167482653908124
-0.76965781303259440
-0.78455064624594983
-0.79659737028093269
-0.80602592410451246
-0.81304913377449539
-0.81786564511682769
-0.82066080040424061
-0.82160746237418747
-0.82086678872492691
-0.81858896004144621
-0.81491386392686127
-0.80929667881525158
-0.80225830376061724
-0.79395524573393716
-0.78453168240432425
-0.77412033126261004
-0.76284326010683967
-0.75081264279111881
-0.73813146387975415
-0.72489417560650449
-0.71118731031274318
-0.69709005132740798
-0.68267476505473768
-0.66800749685205296
-0.65314843310836934
-0.63815233177454833
-0.62306892344631415
-0.60794328496203276
-0.59281618734701891
-0.57772441981462419
-0.56270109142103719
-0.54777591186484120
-0.53297545282361636
-0.51989104722231871
-0.50693990679029710
-0.49413548678026842
-0.48148978135930132
-0.46901342861571682
-0.45671580892955960
-0.44460513710548227
-0.43268854864329365
-0.42097218049918383
-0.40946124666974848
-0.39816010891127723
-0.38952199911395952
-0.38101422568587695
-0.37263791549556191
-0.36439396322608092
-0.35628304625409574
-0.34830563875994636
-0.34046202510542062
-0.33275231251417586
-0.32517644308816440
-0.31773420519186274
-0.31042524423463247
-0.30591850617877137
-0.30146363881838922
-0.29706047982436806
-0.29270884973580846
-0.28840855278742517
-0.28415937770853333
-0.27996109849449285
-0.27581347515145954
-0.27171625441526309
-0.26766917044520150
-0.26367194549353323
]';

I = (I_add./(gamma(k+1)*Y)).^(1/k);

% ������ ������� A � B
% B = z(1,:) - (gamma(k+1))*y0.*ones(1,2*N);
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
%    F_base(j) = gamma(k+1)*y0(j)*((a0 + S1)/(b0 + S2))^k;
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
%     F(j) = gamma(k+1)*Y(j)*((a0 + S1)/(b0 + S2))^k;
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