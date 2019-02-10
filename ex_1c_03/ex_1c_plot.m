phi=0:pi/100:2*pi;
x=cos(phi);
b=0.4245797599366;
y=b*sin(phi);
X=0.375;
Y=0.5;
plot(x,y)
hold on
line([0.358131 X],[0.396418 Y]);
hold on
line([0.770525 X],[-0.270632 Y]);
hold on
line([0.770524 X],[-0.270632 Y]);
hold on
line([-0.984247 X],[-0.075066 Y]);
hold off
axis equal
