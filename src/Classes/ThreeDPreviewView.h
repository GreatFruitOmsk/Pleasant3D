//
//  ThreeDPreviewView.h
//  Pleasant3D
//
//  Created by Eberhard Rensch on 11.02.10.
//  Copyright 2010 Pleasant Software. All rights reserved.
//
//  This program is free software; you can redistribute it and/or modify it under
//  the terms of the GNU General Public License as published by the Free Software 
//  Foundation; either version 3 of the License, or (at your option) any later 
//  version.
// 
//  This program is distributed in the hope that it will be useful, but WITHOUT ANY 
//  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A 
//  PARTICULAR PURPOSE. See the GNU General Public License for more details.
// 
//  You should have received a copy of the GNU General Public License along with 
//  this program; if not, see <http://www.gnu.org/licenses>.
// 
//  Additional permission under GNU GPL version 3 section 7
// 
//  If you modify this Program, or any covered work, by linking or combining it 
//  with the P3DCore.framework (or a modified version of that framework), 
//  containing parts covered by the terms of Pleasant Software's software license, 
//  the licensors of this Program grant you additional permission to convey the 
//  resulting work.
//

#import <Cocoa/Cocoa.h>

@class Vector3, P3DMachineDriverBase;
@interface ThreeDPreviewView : NSOpenGLView
{
	CGFloat _cameraOffset;
	CGFloat _cameraTranslateX;
	CGFloat _cameraTranslateY;
	GLfloat _trackBallRotation[4];
	GLfloat _worldRotation[4];
    
	BOOL _zoomCamera;
	BOOL _translateCamera;
	
	NSTimer* _autorotateTimer;
	
	NSPoint _localMousePoint;
    
    BOOL _validPerspective;
    
	GLuint _arrowDL;
	BOOL _readyToDraw;
}

@property (assign, nonatomic) NSUInteger currentLayer;
@property (assign, nonatomic) BOOL showArrows;
@property (assign, nonatomic) BOOL threeD;
@property (assign, nonatomic) CGFloat othersAlpha;
@property (assign) BOOL autorotate;
@property (assign) BOOL userRequestedAutorotate;
@property (readonly) NSInteger maxLayers;
@property (assign, nonatomic) float currentLayerHeight;
@property (readonly) float layerHeight;
@property (weak, nonatomic) P3DMachineDriverBase* currentMachine;
@property (readonly) Vector3* objectDimensions;

- (IBAction)resetPerspective:(id)sender;

- (void)renderContent;

- (void)setupPlatformVBOWithBufferName:(GLuint)bufferName;
- (GLsizei)setupPlatformRasterVBOWithBufferName:(GLuint)bufferName;

@end
