clc
clear all
close all

format long

k = 1; N = 4;
n = 0:N+1; m = 0:N;

a = [1 ...
     0.2715113138214362780964488 ...
     0.0562661238060587633169245 ...
     0.0067420740469345689743873 ...
     0.0005169505155333205859985 ...
     0.0000194771836765773190602];
b = [1 ...
     0.0215113138214352840651584 ...
     0.0231105175729721417901084 ...
     0.0003669081577365413477999 ...
     0.0000610424408732720110769];
 
x = 0:0.1:50;
y = log(1 + exp(x));

x_minus = 0:-0.1:-50;
y_minus = log(1 + exp(x_minus));

c3 = ((k+1)*pi^2)/(gamma(k+2)^(6/k));
c4 = 1/(gamma(k+2)^(6/k));
% c1 = 1.15, c2 = 1.99
x_probe = [-0.3; 1.8];
y_probe = log(1+exp(x_probe));
if (x_probe(1) ~=0 || x_probe(2) ~= 0)
    y_probe_m = log(1+exp(-x_probe));
else
    y_probe_m = y_probe;
end
y_interp = [y_probe y_probe.^2];

if x_probe(1) ~=0 || x_probe(2) ~= 0
    P_probe = x_probe.^2/2 + pi^2/6;
end

for i = 1:length(y_probe)
    I_minus(i) = gamma(k+1)*y_probe_m(i).*(sum(a.*(y_probe_m(i).^n))/sum(b.*(y_probe_m(i).^m)))^k;
end
if x_probe(1) ~=0 || x_probe(2) ~= 0
    I = P_probe + ((-1)^k)*I_minus';
else 
end

Right = (I./(gamma(k+1)*y_probe)).^(6/k) - 1 - c3*y_probe.^4 - c4*y_probe.^6;
C = inv(y_interp)*Right;
% c1 = C(1); c2 = C(2);
%% c1 =  1.150683011187435, c2 = 1.987584903904907
c1 = 1.15; c2 = 1.99;

P = x.^2/2 + pi^2/6;
for i = 1: length(y)
    I_precesion_minus(i) = gamma(k+1)*y_minus(i).*(sum(a.*(y_minus(i).^n))/sum(b.*(y_minus(i).^m)))^k;
    I_precesion(i) = P(i) + ((-1)^k)*I_precesion_minus(i);

end
% I_approximate = gamma(k+1)*y.*(1 + c1*y+c2*y.^2+c3*y.^4 + c4*y.^6).^(k/6);
% I_approximate_minus = gamma(k+1)*y_minus.*(1 + c1*y_minus+c2*y_minus.^2+c3*y_minus.^4 + c4*y_minus.^6).^(k/6);

I_approximate = (1 + c1*y+c2*y.^2+c3*y.^4 + c4*y.^6);
I_approximate_minus = (1 + c1*y_minus+c2*y_minus.^2+c3*y_minus.^4 + c4*y_minus.^6);

% delta = (I_approximate./I_precesion) - 1;
% delta_minus = (I_approximate_minus./I_precesion_minus) - 1; 

delta = (I_approximate.*(gamma(k+1)*y./I_precesion).^(6/k) - 1)*(k/6);
delta_minus = (I_approximate_minus.*(gamma(k+1)*y_minus./I_precesion_minus).^(6/k) - 1)*(k/6);    
d = [delta_minus, delta];
hold on, grid on
plot([x_minus, x], d, 'k', 'linewidth',2)

% plot([-10,0;30,0],[0,-0.01;0,0.01],'k','linewidth',1.5);
% axis([-30 30 -2.5 1]),grid on
