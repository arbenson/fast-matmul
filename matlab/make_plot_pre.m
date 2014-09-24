function make_plot_pre(width, height)

% Defaults for this blog post
alw = 3;    % AxesLineWidth
fsz = 20;      % Fontsize

figure;
pos = get(gcf, 'Position');
set(gcf, 'Position', [pos(1) pos(2) width*100, height*100]); %<- Set size
set(gca, 'FontSize', fsz, 'LineWidth', alw); %<- Set properties
