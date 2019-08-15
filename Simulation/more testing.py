from graphics import *
import math

width = 500
height = 500

NORTH = 0
EAST = 1
SOUTH = 2
WEST = 3

win = GraphWin('Polygon Rotation Testing',width,height)

def drawGrid():
	for i in range(10):
		line = Line(Point(i*width/10,0),Point(i*width/10,height))
		line.draw(win)

	for j in range(10):
		line = Line(Point(0,j*height/10),Point(width,j*height/10))
		line.draw(win)

def grid(row, col):
	return row*width/10,col*height/10

def rotatePoint(centerPoint,point,angle):
    """Rotates a point around another centerPoint. Angle is in degrees.
    Rotation is counter-clockwise"""
    angle = math.radians(angle)
    temp_point = point[0]-centerPoint[0] , point[1]-centerPoint[1]
    temp_point = ( temp_point[0]*math.cos(angle)-temp_point[1]*math.sin(angle) , temp_point[0]*math.sin(angle)+temp_point[1]*math.cos(angle))
    temp_point = temp_point[0]+centerPoint[0] , temp_point[1]+centerPoint[1]
    return temp_point

def rotatePolygon(polygon,origin,theta):
    """Rotates the given polygon which consists of corners represented as (x,y),
    around the ORIGIN, clock-wise, theta degrees"""
    rotatedPolygon = []
    for corner in polygon :
        rotatedPolygon.append(rotatePoint(origin,corner,theta))
    return rotatedPolygon

# def rotatePolygon(polygon,theta):
#     """Rotates the given polygon which consists of corners represented as (x,y),
#     around the ORIGIN, clock-wise, theta degrees"""
#     theta = math.radians(theta)
#     rotatedPolygon = []
#     for corner in polygon :
#         rotatedPolygon.append(( corner[0]*math.cos(theta)-corner[1]*math.sin(theta) , corner[0]*math.sin(theta)+corner[1]*math.cos(theta)) )
#     return rotatedPolygon


my_polygon = [(200,200),(300,200),(300,300),(200,300)]
# print rotatePolygon(my_polygon,90)

def draw_poly(poly):
	first = None
	second = None
	for point in poly:
		if not first:
			first = point
		elif not second:
			second = point
			l = Line(Point(first[0],first[1]),Point(second[0],second[1]))
			l.setWidth(5)
			l.setFill('black')
			l.draw(win)
		else:
			l = Line(Point(second[0],second[1]),Point(point[0],point[1]))
			l.setWidth(5)
			l.setFill('black')
			l.draw(win)
			second = point
	l = Line(Point(second[0],second[1]),Point(first[0],first[1]))
	l.setWidth(5)
	l.setFill('black')
	l.draw(win)

def main():
	drawGrid()
	draw_poly(my_polygon)
	origin = (250,250)
	draw_poly(rotatePolygon(my_polygon,origin,45))
	win.getMouse()
	win.close()

main()
