from graphics import *
import math

width = 500
height = 500

win = GraphWin('Rectangle Rotation Testing',width,height)

def grid(row, col):
	return row*width/10,col*height/10

class Rect():
	def __init__(self,pivot,l,w):
		self.pivot = pivot
		self.l = l*width/10
		self.w = w*height/10
		self.angle = 90

		self.x = pivot[0]+self.w/2
		self.y = pivot[1]+self.w/2
		self.a = self.x-self.w
		self.b = self.y
		self.c = self.a
		self.d = self.y-self.l
		self.e = self.x
		self.f = self.b-self.l

		self.xy_angle = math.sqrt((self.x-self.pivot[0])**2+(self.y-self.pivot[1])**2)
		print self.xy_angle

		# print self.pivot,self.l,self.w
		# print self.x,self.y,self.a,self.b,self.c,self.d,self.e,self.f
		# print self.w/2

		self.mx = self.pivot[0]
		self.my = self.pivot[1]+self.w/2
		self.nx = self.pivot[0]
		self.ny = self.pivot[1]-self.l+self.w/2

		self.x_0 = self.x
		self.y_0 = self.y
		self.a_0 = self.a
		self.b_0 = self.b 
		self.c_0 = self.c
		self.d_0 = self.d
		self.e_0 = self.e
		self.f_0 = self.f
		self.mx_0 = self.mx
		self.my_0 = self.my
		self.nx_0 = self.nx
		self.ny_0 = self.ny

		self.l1 = None
		self.l2 = None
		self.l3 = None
		self.l4 = None
		self.r5 = None
		self.r6 = None
		
		self.draw()

	def draw(self):
		# print self.x,self.y
		self.l1 = Line(Point(self.x,self.y),Point(self.a,self.b))
		self.l2 = Line(Point(self.a,self.b),Point(self.c,self.d))
		self.l3 = Line(Point(self.c,self.d),Point(self.e,self.f))
		self.l4 = Line(Point(self.e,self.f),Point(self.x,self.y))

		r1 = Line(Point(self.x,self.y),Point(self.pivot[0],self.pivot[1]))
		r1.setWidth(5)
		r1.draw(win)
		# r2 = Line(Point(self.a,self.b),Point(self.pivot[0],self.pivot[1]))
		# r2.setWidth(2)
		# r2.draw(win)
		# r3 = Line(Point(self.c,self.d),Point(self.pivot[0],self.pivot[1]))
		# r3.setWidth(2)
		# r3.draw(win)
		# r4 = Line(Point(self.e,self.f),Point(self.pivot[0],self.pivot[1]))
		# r4.setWidth(2)
		# r4.draw(win)


		self.r5 = Line(Point(self.mx,self.my),Point(self.pivot[0],self.pivot[1]))
		self.r5.setWidth(15)
		self.r5.setFill('red')
		# self.r5.draw(win)

		self.r6 = Line(Point(self.nx,self.ny),Point(self.pivot[0],self.pivot[1]))
		self.r6.setWidth(15)
		self.r6.setFill('blue')
		# self.r6.draw(win)


		self.l1.setWidth(5)
		self.l2.setWidth(5)
		self.l3.setWidth(5)
		self.l4.setWidth(5)
		self.l1.setFill('red')
		self.l2.setFill('blue')
		self.l3.setFill('green')
		self.l4.setFill('yellow')
		# self.l1.draw(win)
		# self.l2.draw(win)
		# self.l3.draw(win)
		# self.l4.draw(win)

		#show pivot point
		p = Point(self.pivot[0],self.pivot[1])
		p.setFill('red')
		p.draw(win)

	def undraw(self):
		self.l1.undraw()
		self.l2.undraw()
		self.l3.undraw()
		self.l4.undraw()
		self.r5.undraw()
		self.r6.undraw()

	def rotate(self,angle):
		self.x = self.x_0
		self.y = self.y_0
		self.a = self.a_0
		self.b = self.b_0
		self.c = self.c_0
		self.d = self.d_0
		self.e = self.e_0
		self.f = self.f_0
		self.mx = self.mx_0
		self.my = self.my_0
		self.nx = self.nx_0
		self.ny = self.ny_0
		# if angle > 180:
		# 	print "Angle is greater than 180 degrees"
		# 	return

		# xy_radius = math.sqrt((self.pivot[0]-self.x)**2+(self.pivot[1]-self.y)**2)
		# ab_radius = math.sqrt((self.pivot[0]-self.a)**2+(self.pivot[1]-self.b)**2)
		# print xy_radius,ab_radius
		# self.undraw()
		# print self.x,self.y,self.a,self.b
		self.x,self.y = rotate(self.pivot,(self.x,self.y),self.xy_angle+angle)
		# self.a,self.b = rotate(self.pivot,(self.a,self.b),angle)
		# self.c,self.d = rotate(self.pivot,(self.c,self.d),angle)
		# self.e,self.f = rotate(self.pivot,(self.e,self.f),angle)
		self.mx,self.my = rotate(self.pivot,(self.mx,self.my),angle)
		self.nx,self.ny = rotate(self.pivot,(self.nx,self.ny),angle)

		# print math.sqrt((self.e-self.pivot[0])**2+(self.f-self.pivot[1])**2)
		# print self.x,self.y,self.a,self.b
		# print self.x,self.y
		# self.undraw()
		self.draw()
		self.xy_angle = angle
		self.angle = angle

def rotate(origin,point,angle):
	ox,oy = origin
	px,py = point

	angle = math.radians(angle)

	qx = ox + math.cos(angle) * (px - ox) - math.sin(angle) * (py - oy)
	qy = oy + math.sin(angle) * (px - ox) - math.cos(angle) * (py - oy)
	return qx,qy

def line_rotate():
	x = 250
	y = 250
	a = 350
	b = 250
	l = Line(Point(x,y),Point(a,b))
	l.setWidth(5)
	l.draw(win)

	colors = ['red','black','blue','yellow','green','navy','orange','brown','purple','gray','pink','tan']

	for i in range(180):
		x = 250
		y = 250
		a = 250
		b = 100
		# print i*30,colors[i]
		a,b = rotate((x,y),(a,b),(i*2))

		l = Line(Point(x,y),Point(a,b))
		l.setWidth(5)
		l.setFill('black')
		l.draw(win)

def main():
	#FIX = need individual points for each corner of the rectangle, not 2 points to create the rectangle
	r = Rect((250,250),2,0.5)
	for i in range(180):
		r.rotate(i*2)
	# r.rotate(30)
	# r.rotate(45)
	# r.rotate(60)
	# r.rotate(75)
	# r.rotate(90)
	# r.rotate(90)
	# r.rotate(90)
	# for i in range(6):
	# 	r.rotate(i*(90/6))
	# line_rotate()
	win.getMouse()
	win.close()

main()
