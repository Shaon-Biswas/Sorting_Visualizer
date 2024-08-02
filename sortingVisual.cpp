#include<SDL2/SDL.h>
#include<bits/stdc++.h>
#include<iostream>
#include<random>
#include<ranges>
#include<algorithm>

using namespace std;

void draw_state(vector<int>& v, SDL_Renderer* renderer, int red, int blue)
{
    int index=0;
    for(int i : v)
    {
        if(index==red)
        {
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        }
        else if(index==blue)
        {
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        }
        else{
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }
        
        SDL_RenderDrawLine(renderer, index, 99, index, i);
        index+=1;
    }
}

void bubbleSort(vector<int>& v)
{
    for(int i=0;i<v.size();i++)
    {
        for(int j=i;j<v.size();j++)
        {
            if(v[j]<v[i])
            {
                swap(v[j],v[i]);
            }
            // Clear screen

            SDL_SetRenderDrawColor(renderer,0,0,0,255);
            SDL_RenderClear(render);

            // Draw the state of the sort..

            draw_state(v, renderer, i, j);

            // Show to window

            SDL_RendererPresent(renderer);
            SDL_Delay(10);
        }
    }
}

void selectionSort(vector<int>& v)
{
    for(i=0;i<=v.size()-2;i++)
    {
        int min=i;
        for(j=i;j<=v.size()-1;j++)
        {
            if(v[j]<v[min])
            {
                min=j;
            }
        }
        swap(v[i],v[min]);
        
         // Clear screen

        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(render);
         // Draw the state of the sort..

        draw_state(v, renderer, i, j);

        // Show to window

        SDL_RendererPresent(renderer);
        SDL_Delay(10);
    }
}
void insertionSort(vector<int>& v)
{
    for(int i=0;i<v.size()-1)
    {
        int j=i;
        while(j>0 && v[j-1]>v[j])
        {
            swap(v[j-1],v[j]);
        }
        //Clear screen
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(render);
         // Draw the state of the sort..

        draw_state(v, renderer, i, j);

        // Show to window

        SDL_RendererPresent(renderer);
        SDL_Delay(10);
    }
}

int main()
{
    random_device rd;
    uniform_int_distribution d(1,99);
    vector<int>v;
    for(int i=0;i<100;i++)
    {
        v.push_back(d(rd));
    }

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_CreateWindowAndRenderer(100*10, 100*10, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, 10, 10);
    // sorting.......
    // for(int i=0;i<v.size();i++)
    // {
    //     for(int j=i;j<v.size();j++)
    //     {
    //         if(v[j]<v[i])
    //         {
    //             swap(v[j],v[i]);
    //         }
    //         // Clear screen

    //         SDL_SetRenderDrawColor(renderer,0,0,0,255);
    //         SDL_RenderClear(render);

    //         // Draw the state of the sort..

    //         draw_state(v, renderer, i, j);

    //         // Show to window

    //         SDL_RendererPresent(renderer);
    //         SDL_Delay(10);
    //     }
    // }

    cout<<" For Visualize The Sorting algorithm Give a Command Accordingly.\n"
    <<" For bubble sort enter 1.\n"
    <<" For selection sort enter 2.\n"
    <<" For insertion sort enter 3.\n"
    <<" For merge sort enter 4.\n"
    <<" For quick sort enter 5.\n"<<endl;
    cin>>n;
    
    if(n==1)
    {
        bubbleSort(v);
    }
     else if(n==2)
    {
        selectionSort(v);
    }
    else if(n==3)
    {
        insertionSort(v);
    }
    else if(n==4)
    {
        mergeSort(v);
    }
    else if(n==5)
    {
        quickSort(v);
    }
    else{
        cout<<"You oress the wrong key"<<endl;
    }

}