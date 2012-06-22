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
    Core::Float2 TouchPoint(touchLocation.x - 20, touchLocation.y - 20);
    
    NSPoint pPoint;
    pPoint.x = touchLocation.x - 20;
    pPoint.y = touchLocation.y - 20;
    
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
        NSPoint pPoint = [pValue pointValue];
        
        
        NSRect rect = NSMakeRect(pPoint.x, pPoint.y, 10, 10);
        NSBezierPath* circlePath = [NSBezierPath bezierPath];
        [circlePath appendBezierPathWithOvalInRect: rect];
        
        // Outline and fill the path
        CGContextSetRGBFillColor(context, 1.0, 0.0, 0.0, 1.0);
        [circlePath fill];
    }];
    
    
    //draw interpolation
    for (float i = m_CubicSpline.MinX(); i < m_CubicSpline.MaxX(); i+=0.5f) 
    {
        float y = m_CubicSpline.Interpolate(i);
        
        NSRect rect = NSMakeRect(i, y, 2, 2);
        NSBezierPath* circlePath = [NSBezierPath bezierPath];
        [circlePath appendBezierPathWithOvalInRect: rect];
        
        // Outline and fill the path
        CGContextSetRGBFillColor(context, 0.0, 1.0, 0.0, 1.0);
        [circlePath fill];
    }
    
    
    [NSGraphicsContext restoreGraphicsState];
}

@end
