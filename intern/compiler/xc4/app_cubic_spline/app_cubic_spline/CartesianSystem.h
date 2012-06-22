//
//  CartesianSystem.h
//  app_cubic_spline
//
//  Created by Tobias Schwandt on 22.06.12.
//  Copyright (c) 2012 Zebresel. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#import "core/cubic_spline.h"

@interface CartesianSystem : NSImageView
{
    NSMutableArray*          m_pPoints;
    Core::Math::CCubicSpline m_CubicSpline;
}

@end
