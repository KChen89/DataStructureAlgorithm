#include<stdio.h>
#include<stdlib.h>
#include"headers.h"


gImg* gImgInit(const unsigned height, const unsigned width){
    gImg* image2d = malloc(sizeof(gImg));
    if(!image2d){
        printf("Allocate mem. (gImg) failed\n");
        return NULL;
    }
    image2d->matrix = (PIXEL**) malloc(sizeof(int*) * height);
    if(!image2d->matrix){
        printf("Allocate mem (image) failed\n");
        return NULL;
    } 
    for(int i=0;i<height;i++){
        image2d->matrix[i] = (PIXEL*) malloc(sizeof(PIXEL*) * width);
        if(!image2d->matrix[i]){
            printf("Allocate mem (row %d) failed", i);
            return NULL;
        }
    }
    image2d->height = height;
    image2d->width  = width;
    return image2d;  
}

bool setValue(gImg* image, const unsigned y, const unsigned x, const PIXEL value){
    if(!image || !image->matrix || !image->matrix[y]){
        printf("Uninitialized pointer\n");
        return false;
    }
    image->matrix[y][x] = value;
    return true;
}

bool getValue(gImg* image, const unsigned y, const unsigned x, PIXEL* value){
    if(!image || !image->matrix || !image->matrix[y]){
        printf("Uninitialized pointer\n");
        return false;
    }
    *value = image->matrix[y][x];
    return true;
}

void showImage(gImg* const image){
    if(!image ||!image->matrix){
        printf("Uninitialized pointer\n");
        return;
    }
    for(int i=0; i<image->height; i++){
        for(int j=0; j<image->width; j++){
            printf("%02x: ", image->matrix[i][j]);
        }
        printf("\n");
    }
}

bool setZero(gImg* const image){
    if(!image || !image->matrix){
        printf("Uninitialize pointer\n");
        return false;
    }

    for(int i=0; i<image->height; i++){
        for(int j=0; j<image->width; j++){
            if(!setValue(image, i, j, 0)){
                return false;
            }
        }
    }
    return true;
}

bool setMax(gImg* const image){
    if(!image || !image->matrix){
        printf("Uninitialize pointer\n");
        return false;
    }
    for(int i=0; i<image->height; i++){
        for(int j=0; j<image->width; j++){
            if(!setValue(image, i, j, 0xff)){
                return false;
            }
        }
    }
    return true;
}

void freeGImg(gImg** gIP){
    gImg* image = *gIP;
    if(!image || !image->matrix){
        printf("Uninitialize pointer\n");
        return;
    }
    for(int i=0;i<image->height;i++){
        free(image->matrix[i]);
        image->matrix[i] = NULL;
    }
    free(image->matrix);
    image->matrix = NULL;
    free(image);
    *gIP = NULL;
}