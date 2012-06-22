//
//  CartesianSystem.m
//  app_cubic_spline
//
//  Created by Tobias Schwandt on 22.06.12.
//  Copyright (c) 2012 Zebresel. All rights reserved.
//

#import "CartesianSystem.h"

#import "core/vector2.h"

@implementation CartesianSystem

- (void)awakeFromNib
{
    m_pPoints = [[NSMutableArray alloc] initWithCapacity:2];
}

- (void)mouseUp:(NSEvent *)theEvent
{
    CGPoint touchLocation = [theEvent locationInWindow];
    Core::Float2 TouchPoint(touchLocation.x, touchLocation.y);
    
    NSPoint pPoint;
    pPoint.x = touchLocation.x;
    pPoint.y = touchLocation.y;
    
    [m_pPoints addObject:[NSValue valueWithPoint:pPoint]];
    
    //add point to spline
    m_CubicSpline.AddPoint(TouchPoint);
    
    [self setNeedsDisplay:YES];
}

- (void)drawRect:(NSRect)dirtyRect
{
    //draw cartesian system (simple)
    CGContextRef context = (CGContextRef)[[NSGraphicsContext currentContext] graphicsPort];             
    CGContextSetRGBStrokeColor(context, 0.0, 0.0, 0.0, 1.0);
    CGContextSetLineWidth(context, 2.0);
    
    float x = self.frame.size.width  / 2;
    float y = self.frame.size.height / 2;
    
    CGContextBeginPath(context);
    CGContextMoveToPoint(context, x, 0);
    CGContextAddLineToPoint(context, x, self.frame.size.height);
    CGContextStrokePath(context);
    
    CGContextBeginPath(context);
    CGContextMoveToPoint(context, 0, y);
    CGContextAddLineToPoint(context, self.frame.size.width, y);
    CGContextStrokePath(context);
    
    
    //draw points
    [m_pPoints enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop) 
    {
        //draw points

        NSValue* pValue = (NSValue*)obj;
        NSPoint Point = [pValue pointValue];
        
        
        NSRect rect = NSMakeRect(Point.x, Point.y, 5, 5);
        NSBezierPath* circlePath = [NSBezierPath bezierPath];
        [circlePath appendBezierPathWithOvalInRect: rect];
        
        // Outline and fill the path
        CGContextSetRGBFillColor(context, 1.0, 0.0, 0.0, 1.0);
        [circlePath fill];
    }];
    
    
    //draw interpolation
    CGContextSetRGBStrokeColor(context, 0.0, 0.6, 1.0, 1.0);
    
    Core::Float2 LastPoint;
    Core::Float2 ActualPoint;
    
    for (float x = m_CubicSpline.MinX(); x < m_CubicSpline.MaxX(); x += 3.0f) 
    {
        float y = m_CubicSpline.Interpolate(x);
        
        ActualPoint[0] = x;
        ActualPoint[1] = y;
        
        if (ActualPoint[0] > m_CubicSpline.MinX()) 
        {
            CGContextBeginPath(context);
            CGContextMoveToPoint(context, LastPoint[0], LastPoint[1]);
            CGContextAddLineToPoint(context, ActualPoint[0], ActualPoint[1]);
            CGContextStrokePath(context);
        }
        
        LastPoint = ActualPoint;
    }
    
    
    [NSGraphicsContext restoreGraphicsState];
}

@end
