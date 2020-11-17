package com.example.nametodolist;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.Button;
import android.widget.TextView;

import androidx.constraintlayout.widget.ConstraintLayout;

import java.util.ArrayList;
import java.util.List;

public class CustomAdapter extends BaseAdapter {
    Context mContext;
    LayoutInflater mLayoutInflater;
    List<String> tasksList = new ArrayList<>();

    @Override
    public int getCount() {
        return tasksList.size();
    }

    @Override
    public Object getItem(int position) {
        return tasksList.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        ConstraintLayout itemView;
        if (convertView == null) {
            itemView = (ConstraintLayout) mLayoutInflater.inflate(
                    R.layout.todo_item, parent, false);
        } else {
            itemView = (ConstraintLayout) convertView;
        }

        TextView taskTitle = itemView.findViewById(R.id.task_title);
        taskTitle.setText(tasksList.get(position));

        Button button = itemView.findViewById(R.id.task_delete);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tasksList.remove(position);
                notifyDataSetChanged();
            }
        });

        return itemView;
    }


    public CustomAdapter(Context context, List<String> tasksList) {
        this.mContext = context;
        this.mLayoutInflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        this.tasksList = tasksList;
    }
}
